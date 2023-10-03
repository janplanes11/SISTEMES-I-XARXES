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
}
//lock y unlock deben estar separados lo minimo necesario 
// para que no se pare el codigo del juego MUCHO RATO



