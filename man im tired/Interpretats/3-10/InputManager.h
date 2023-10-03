#pragma once
#include <mutex>
class InputManager
{
public:
	InputManager();
	~InputManager();
	void StartListener();
	void StopListener();
	unsigned int AddListener(int keyCode);
	void RemoveList(unsigned int listenerId);
private:
	std::mutex* _isStartedMutex = new std::mutex();
	bool _isStarted = false;
	std::thread* _listenerThread;
	void ReadLoop();
};

