#include "mainMenu.h"

void MainMenu::emailValidation() {
    while (email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
        std::cout << std::setw(56) << "                    Enter your email: ";
        std::cin >> email;

        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
            std::cout << std::setw(97) << "|                                                                        |\n";
            std::cout << std::setw(80) << "\033[31mEnter valid email! Please try again.\n";
            sleepMs(1500);
            std::cout << std::setw(101) << "\033[0m|                                                                        |\n";
        }        
    }
}

void MainMenu::passwordValidation() {
    while (!hasUpper || !hasDigit || !hasSpecialChar || !passLength) {
        std::cout << std::setw(56) << "                    Enter your pasword: ";
        std::cin >> password;

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
              std::cout << std::setw(97) << "|                                                                        |\n";
              std::cout << std::setw(120)
              << "\033[31mPassword must contain at least one uppercase letter, one number, and one special character. "
              << "Must be at least 8 characters long. Please try again.\n";
              sleepMs(1500);
              std::cout << std::setw(101) << "\033[0m|                                                                        |\n";
        }
    }
}

void MainMenu::passwordMatch() {
    while (password != confirmPassword) {
        std::cout << std::setw(56) << "                    Confirm Password: ";
        std::cin >> confirmPassword;

        if (password != confirmPassword) {
            std::cout << std::setw(97) << "|                                                                        |\n";
            std::cout << std::setw(80) << "\033[31mPasswords do not match. Please try again!\n";
            sleepMs(1500);
            std::cout << std::setw(101) << "\033[0m|                                                                        |\n";
        }
    }
}

void MainMenu::usernameValidation() {
    while (!hasUpper) {
        std::cout << std::setw(59) << "                    Enter your username: ";
        std::cin >> username;
        hasUpper = false;

        for (char ch : username) {
            if (std::isupper(ch)) hasUpper = true;
        }
        if (!hasUpper) {
            std::cout << std::setw(97) << "|                                                                        |\n";
            std::cout << std::setw(90) << "\033[31mUsername must contain at least one uppercase letter. Please try again.\n";
            sleepMs(1500);
            std::cout << std::setw(101) << "\033[0m|                                                                        |\n";
        }
    }
}
