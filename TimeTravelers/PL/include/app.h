#pragma once
#include "precompile.h"
#include "mainMenu.h"

class PageBools {
public:
	bool isInMainMenu = true;
};


class App {
public:
	App();
	void display();
	void pageHandler();
	void update();

private:
	PageBools pages;
	MainMenu mainMenu;
};