#pragma once
#include <iostream>
#include <chrono>
#include <string>

#pragma region Functions Declaration Header

void PrintElapsedTime(std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end);
void Count(unsigned long long maxCounter);
void Example01();
void Example02();
void Example03();
void Example04();
void Example05();
void Example06();
void Example07();

#pragma endregion

#pragma region Global Variables

std::chrono::system_clock::time_point startDate;

#pragma endregion

int main()
{
    startDate = std::chrono::system_clock::now();

    int exampleUsed = 1;

    switch (exampleUsed)
    {
    case 1:
        Example01();
        break;
    case 2:
        Example02();
        break;
    case 3:
        Example03();
        break;
    case 4:
        Example04();
        break;
    case 5:
        Example05();
        break;
    case 6:
        Example06();
        break;
    case 7:
        Example07();
        break;
    default:
        break;
    }

    std::cout << "Example 0" << exampleUsed << " finished" << std::endl;
    std::string text = "";
    std::getline(std::cin, text);
}

void Example01()
{

}

void Example02()
{

}

void Example03()
{

}

void Example04()
{

}

void Example05()
{

}

void Example06()
{

}
void Example07()
{

}