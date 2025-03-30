#pragma once
#include "precompile.h"

class MainMenu {
public:
	void displayMainMenu();
	void loginHandler();
	void registerHandler();
	void emailValidation();
	void passwordValidation();
	void passwordMatch();
	void usernameValidation();

private:
	int choice;

	std::string email;
	std::string userName;
	std::string password;
	std::string confirmPassword;

	bool hasUpper = false;
	bool hasDigit = false;
	bool hasSpecialChar = false;
	bool passLength = false;

};
