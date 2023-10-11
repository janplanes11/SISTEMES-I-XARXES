// Ejericio_Pregunta_y_respuestas.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <Windows.h>
#include "Timer.h"
#include "QuestionManager.h"
#include "Ejericio_Pregunta_y_respuestas.h"
void Answer() {
    std::cout << "Respuesta era 12";
}
int main()
{
    int input;
    Question* TestQuestions = new Question("Donde esta mi padre?");
    Timer::StartTimer(5, [TestQuestions]() {
        TestQuestions->DrawQuestion();
        });
     
    Timer::DetectInput(input);
    while (true) {

    }
}

