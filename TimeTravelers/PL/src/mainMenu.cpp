#include "mainMenu.h"


void MainMenu::displayMainMenu() {
    std::cout << " _____ _                  _____                    _ _               " << std::endl;
    std::cout << "|_   _(_)_ __ ___   ___  |_   _| __ __ ___   _____| | | ___ _ __ ___ " << std::endl;
    std::cout << "  | | | | '_ ` _ \\ / _ \\   | || '__/ _` \\ \\ / / _ \\ | |/ _ \\ '__/ __|" << std::endl;
    std::cout << "  | | | | | | | | |  __/   | || | | (_| |\\ V /  __/ | |  __/ |  \\__ \\" << std::endl;
    std::cout << "  |_| |_|_| |_| |_|\\___|   |_||_|  \\__,_| \\_/ \\___|_|_|\\___|_|  |___/" << std::endl;

    

    std::cout << "1. Login\n";
    std::cout << "2. Register\n";
    std::cout << "3. Exit\n";

    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: MainMenu::loginHandler(); break;
    case 2: MainMenu::registerHandler(); break;
    case 3: break;
    default: std::cout << "Invalid input. Please try again!\n"; return;
    }
}

void MainMenu::loginHandler() {
    std::cout << '\n';
}

void MainMenu::registerHandler() {
    system("cls");
    std::cout << "Enter your email: ";
    std::cin >> email;
    emailValidation();


    std::cout << "\nEnter your username: ";
    std::cin >> userName;
    usernameValidation();

    std::cout << "\nEnter your password: ";
    std::cin >> password;
    passwordValidation();

    std::cout << "\nConfirm password: ";
    std::cin >> confirmPassword;
    passwordMatch();

    if (RegisterManager::registerUser(userName, password)) {
        std::cout << "User registered successfully!\n";
    }
    else {
        std::cout << "Registration failed!\n";
    }
}