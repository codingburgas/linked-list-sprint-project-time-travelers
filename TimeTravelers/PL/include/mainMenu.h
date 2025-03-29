#pragma once
#include "precompile.h"

class MainMenu {
public:
	void displayMainMenu();
	void loginHandler();
	void registerHandler();

private:
	int choice;

	std::string email;
	std::string userName;
	std::string password;
	std::string confirmPass;
};