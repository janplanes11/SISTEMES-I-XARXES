#include "InputManager.h"
#include "ConsoleControl.h"
InputManager::InputManager()
{



}

InputManager::~InputManager()
{


}

void InputManager::StartListener()
{
	_isStartedMutex->lock();
	if (_isStarted) {
		_isStartedMutex->unlock();
		return;
	}
	_isStarted = true;
	_isStartedMutex->unlock();
	_listenerThread = new std::thread(&ReadLoop, this);
	_listenerThread->detach();
}
void InputManager::ReadLoop()
{
	_isStartedMutex->lock();
	bool isStarted = true;
	_isStartedMutex->unlock();
	while (_isStarted) 
	{
		int keyCode = ConsoleControl::WaithForReadNextKey();
		//^Search in KeyBindings Map if pressed keycode exists
		//if it does, call all lamda functions (functions with no name)
		_listenersMapMutex->lock();
		KeyBindingListsMap::iterator pair = _listenersMap->find(keyCode);
		if (pair != _listenersMap->end()) {
			std::list<KeyBinding*>* keyBindings = pair->second;
			for (KeyBinding* keyBinding : *keyBindings) {
				keyBinding->onKeyPress(keyCode);
			}
		}
		_listenersMapMutex->unlock();
		_isStartedMutex->lock();
		isStarted = _isStarted;
		_isStartedMutex->unlock();
	}
}
void InputManager::StopListener()
{
	_isStartedMutex->lock();
	_isStarted = false;
	_isStartedMutex->unlock();
	//lock y unlock deben estar separados lo minimo necesario 
// para que no se pare el codigo del juego MUCHO RATO
}
unsigned int InputManager::AddListener(int keyCode, KeyBinding::OnKeyPress onKeyPress)
{
	KeyBinding* binding = new KeyBinding(keyCode, onKeyPress); 
	_listenersMapMutex->lock();

	KeyBindingListsMap::iterator pair = _listenersMap->find(keyCode);
	std::list<KeyBinding*>* keyBindings = nullptr;
	if (pair == _listenersMap->end()) {
		_listenersMap->emplace(keyCode, keyBindings);
	}
	else {
		keyBindings = pair->second;
	}
	keyBindings->push_back(binding);

	_listenersMapMutex->unlock();
	return binding->GetSubscriptionId();
}
void InputManager::RemoveListener(unsigned int subscriptionId)
{
	_listenersMapMutex->lock();
	for (std::pair<int, std::list<KeyBinding*>*> pair : *_listenersMap) {
		std::list<KeyBinding*>* keyBindings = pair.second;
		for (KeyBinding* binding : *keyBindings) {
			if (binding->GetSubscriptionId() == subscriptionId) {
				keyBindings->remove(binding);
			}
		}
	}
	_listenersMapMutex->unlock();
}


InputManager::KeyBinding::KeyBinding(int keyCode, OnKeyPress onKeyPress)
{
	static std::mutex currentIdMutex = std::mutex();
	currentIdMutex.lock();
	static unsigned int currentId = 0;
	//^gracias a static currentId sera asignado a 0 la primera vez, 
	// la siguiente vez que llame al constructor currentId 
	// no se le asignara el valor 0 sino el que le quedo la ultima vez que se la llamo
	subscriptionId = currentId;
	currentId++;
	currentIdMutex.unlock();
	this->keyCode = keyCode;
	this->onKeyPress = onKeyPress;
}

InputManager::KeyBinding::~KeyBinding()
{
}

unsigned int InputManager::KeyBinding::GetSubscriptionId()
{
	return subscriptionId;
}
