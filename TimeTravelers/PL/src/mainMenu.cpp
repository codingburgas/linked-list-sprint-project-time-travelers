#include "mainMenu.h"

void MainMenu::displayMainMenu() {
    std::cout << std::setw(94) << "       _____ _                  _____                    _ _               \n";
    std::cout << std::setw(94) << "      |_   _(_)_ __ ___   ___  |_   _| __ __ ___   _____| | | ___ _ __ ___ \n";
    std::cout << std::setw(94) << "        | | | | '_ ` _ \\ / _ \\   | || '__/ _` \\ \\ / / _ \\ | |/ _ \\ '__/ __|\n";
    std::cout << std::setw(94) << "        | | | | | | | | |  __/   | || | | (_| |\\ V /  __/ | |  __/ |  \\__ \\\n";
    std::cout << std::setw(94) << "        |_| |_|_| |_| |_|\\___|   |_||_|  \\\__,_| \\_/ \\___|_|_|\\___|_|  |___/\n";
    std::cout << '\n';
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                MAIN MENU                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                1. Login                                |\n";
    std::cout << std::setw(97) << "|                                2. Register                             |\n";
    std::cout << std::setw(97) << "|                                3. Exit                                 |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(60) << "Enter your choice: ";

    std::cin >> choice;

    switch (choice) {
    case 1: MainMenu::loginHandler(); break;
    case 2: MainMenu::registerHandler(); break;
    case 3: break;
    default:
        std::cout << "Invalid input. Please try again!\n";
        return;
    }
}

void MainMenu::loginHandler() {
    system("cls");
    
    std::cout << "Enter your username: ";
    std::cin >> userName;

    std::cout << "\nEnter your password: ";
    std::cin >> password;

    if (!LoginManager::login(userName, password)) {
        Sleep(1500);
        loginHandler();
    }
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
        MainMenu::loginHandler();
    }
    else {
        std::cout << "Registration failed!\n";
    }
}