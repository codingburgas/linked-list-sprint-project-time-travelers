#include "mainMenu.h"

void MainMenu::displayMainMenu() {
    drawTeamName();
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                MAIN MENU                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "|                                1. Login                                |\n";
    std::cout << std::setw(97) << "|                                2. Register                             |\n";
    std::cout << std::setw(97) << "|                                3. Exit                                 |\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
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

void MainMenu::drawTeamName() {
    std::cout << std::setw(94) << "       _____ _                  _____                    _ _               \n";
    std::cout << std::setw(94) << "      |_   _(_)_ __ ___   ___  |_   _| __ __ ___   _____| | | ___ _ __ ___ \n";
    std::cout << std::setw(94) << "        | | | | '_ ` _ \\ / _ \\   | || '__/ _` \\ \\ / / _ \\ | |/ _ \\ '__/ __|\n";
    std::cout << std::setw(94) << "        | | | | | | | | |  __/   | || | | (_| |\\ V /  __/ | |  __/ |  \\__ \\\n";
    std::cout << std::setw(94) << "        |_| |_|_| |_| |_|\\___|   |_||_|  \\\__,_| \\_/ \\___|_|_|\\___|_|  |___/\n";
    std::cout << '\n';
}

void MainMenu::loginHandler() {
    system("cls");
    std::cout << '\n';
    drawTeamName();

    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                LOGIN                                   |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(67) << "                        Enter your username: ";
    std::cin >> username;


    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(67) << "                        Enter your password: ";
    std::cin >> password;
    std::cout << std::setw(97) << "|                                                                        |\n";
    if (!LoginManager::login(username, password)) {
        Sleep(1500);
        loginHandler();
    }
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

}




void MainMenu::registerHandler() {
    system("cls");
    std::cout << '\n';

    drawTeamName();

    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                REGISTER                                |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(56) << "                    Enter your email: ";
    std::cin >> email;
    std::cout << std::setw(97) << "|                                                                        |\n";
    emailValidation();

    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(59) << "                    Enter your username: ";
    std::cin >> username;
    std::cout << std::setw(97) << "|                                                                        |\n";
    usernameValidation();

    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(56) << "                    Enter your pasword: ";
    std::cin >> password;
    passwordValidation();
    
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(56) << "                    Confirm Password: ";
    std::cin >> confirmPassword;
    passwordMatch();

    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "==========================================================================\n";


    if (RegisterManager::registerUser(username, password)) {
        std::cout << "User registered successfully!\n";
        Sleep(1500);
        MainMenu::loginHandler();
    }
    else {
        std::cout << "Registration failed!\n";
    }
}