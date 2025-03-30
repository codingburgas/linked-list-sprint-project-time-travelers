#include "mainMenu.h"

void MainMenu::emailValidation() {
    if (email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
        std::cout << "Enter valid email!\n";
        std::cout << "Please try again!";
        Sleep(1000);
        registerHandler();
    }
}

void MainMenu::passwordValidation() {
    for (char ch : password) {
        if (std::isupper(ch)) hasUpper = true;
        if (std::isdigit(ch)) hasDigit = true;
        if (std::ispunct(ch)) hasSpecialChar = true;
        if (password.length() >= 8) passLength = true;
    }
    if (!hasUpper || !hasDigit || !hasSpecialChar || !passLength) {
        std::cout << "Password must contain at least one uppercase letter, one number, and one special character. Must be at least 8 characters long. Please try again.\n";
        Sleep(1000);
        registerHandler();
    }
}

void MainMenu::passwordMatch() {
    if (password != confirmPassword) {
        std::cout << "Passwords do not match. Please try again!\n";
        Sleep(1000);
        registerHandler();
    }
}

void MainMenu::usernameValidation() {
    for (char ch : userName) {
        if (std::isupper(ch)) hasUpper = true;
    }

    if (!hasUpper) {
        std::cout << "Username must contain at least one uppercase letter. Please try again.\n";
        Sleep(1000);
        registerHandler();
    }
}