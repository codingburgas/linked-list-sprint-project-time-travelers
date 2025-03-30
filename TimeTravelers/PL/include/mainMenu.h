#pragma once
#include "precompile.h"
#include "../../BLL/include/register.h"
#include "../../BLL/include/login.h"

class MainMenu {
public:
	void displayMainMenu();
	void loginHandler();
	void registerHandler();
	void emailValidation();
	void passwordValidation();
	void passwordMatch();
	void usernameValidation();

	void drawTeamName();

private:
	int choice;

	
	std::string email = "";
	std::string username = "";
	std::string password = "";
	std::string confirmPassword = "";

	bool hasUpper = false;
	bool hasDigit = false;
	bool hasSpecialChar = false;
	bool passLength = false;

};
