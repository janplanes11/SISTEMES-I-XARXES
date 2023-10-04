#include <ios>
#include "ConsoleControl.h"
#include "InputManager.h"


void example() {
	ConsoleControl::SetColor(ConsoleControl::BLUE);

	std::cout << "Hello World!" << std::endl;

	ConsoleControl::SetColor(ConsoleControl::WHITE);

	ConsoleControl::SetPosition(5, 5);
	std::cout << "C" << std::endl;

}
void llegirInput() {
	int keyCode = ConsoleControl::WaithForReadNextKey();

	std::cout << "Key code is: " << keyCode << std::endl;
}
int main() {
	
	InputManager* IManager = new InputManager();

	IManager->StartListener();

	while (true) {

	}

	

	return 0;
}