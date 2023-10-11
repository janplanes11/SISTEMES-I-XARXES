#pragma once
#include "ConsoleControl.h"
#include <functional>
class Timer {

public:
	Timer(){}

	typedef std::function<void()>OnTimeElapsed;
	typedef std::function<bool()>OnTimeElapsedLoop;

	static void StartTimer(int seconds, OnTimeElapsed onTimeElapsed);
	static void DetectInput(int input);
	

};