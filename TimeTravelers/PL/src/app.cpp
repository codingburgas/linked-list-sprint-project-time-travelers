#include "app.h"

App::App() {
	update();
}

void App::update() {
	pageHandler();
	display();
}

void App::pageHandler() {
	std::cout << std::endl;
}

void App::display() {
	if (pages.isInMainMenu) {
		mainMenu.displayMainMenu();
	}
}