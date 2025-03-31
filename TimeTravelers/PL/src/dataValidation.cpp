#include "mainMenu.h"

void MainMenu::emailValidation() {
    if (email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
        std::cout << std::setw(80) << "Enter valid email! Please try again.\n";
        Sleep(1500);
        registerHandler();
    }
}

void MainMenu::passwordValidation() {
    hasUpper = false;
    hasDigit = false;
    hasSpecialChar = false;
    passLength = false;

    for (char ch : password) {
        if (std::isupper(ch)) hasUpper = true;
        if (std::isdigit(ch)) hasDigit = true;
        if (std::ispunct(ch)) hasSpecialChar = true;
        if (password.length() >= 8) passLength = true;
    }
    if (!hasUpper || !hasDigit || !hasSpecialChar || !passLength) {
        std::cout << std::setw(120)
            << "Password must contain at least one uppercase letter, one number, and one special character. "
            << "Must be at least 8 characters long. Please try again.\n";
        Sleep(1500);
        registerHandler();
    }
}

void MainMenu::passwordMatch() {
    if (password != confirmPassword) {
        std::cout << "Passwords do not match. Please try again!\n";
        Sleep(1500);
        registerHandler();
    }
}

void MainMenu::usernameValidation() {
    hasUpper = false;

    for (char ch : username) {
        if (std::isupper(ch)) hasUpper = true;
    }

    if (!hasUpper) {
        std::cout << std::setw(90) << "Username must contain at least one uppercase letter. Please try again.\n";
        Sleep(1500);
        registerHandler();
    }
}
