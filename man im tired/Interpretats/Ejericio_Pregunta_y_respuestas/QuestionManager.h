#pragma once
#include <string>
#include <iostream>

class Question {
private:

	std::string _question;

public:

	Question(std::string questionFormed) : _question(questionFormed) {};

	 void DrawQuestion() {
		std::cout << _question << std::endl;
	}

};