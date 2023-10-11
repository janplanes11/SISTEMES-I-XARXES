#include "Timer.h"
#include <Windows.h>

void Timer::StartTimer(int seconds, OnTimeElapsed onTimeElapsed) {
	std::thread* timeUsed = new std::thread([seconds, onTimeElapsed]() {//llamo un in y una funcion, aqui una vez se cuenten los x segundos del int, se llama la funcion
		ConsoleControl::Wait(seconds * 1000);
		onTimeElapsed();
		});
	timeUsed->detach();
}

void Timer::DetectInput(int input)
{
	
	switch (input) {
	case KB_DOWN:
		std::cout << "A" << std::endl;
		break;
	case KB_UP:
		std::cout << "B" << std::endl;
		break;
	default:
		std::cout << "FUCK YOU BITCH" << std::endl;
	}
}
