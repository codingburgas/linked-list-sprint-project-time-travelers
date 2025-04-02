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
    case 1:
        MainMenu::loginHandler();
        break;
    case 2:
        MainMenu::registerHandler();
        break;
    case 3:

        break;
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
    std::cout << std::setw(94) << "        |_| |_|_| |_| |_|\\___|   |_||_|  \\__,_| \\_/ \\___|_|_|\\___|_|  |___/\n";
    std::cout << '\n';
}

void MainMenu::loginHandler() {
#ifdef _WIN64
    system("cls");
#elif __APPLE__
    system("clear");
#endif
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
        sleepMs(1500);
        loginHandler();
    }
    else {
        sleepMs(1500);
        displayUserMenu();
    }

    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
}

void MainMenu::drawRegister() {
#ifdef _WIN64
    system("cls");
#elif __APPLE__
    system("clear");
#endif
    std::cout << '\n';

    drawTeamName();

    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                REGISTER                                |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
    emailValidation();

    std::cout << std::setw(97) << "|                                                                        |\n";
    usernameValidation();

    std::cout << std::setw(97) << "|                                                                        |\n";
    passwordValidation();

    std::cout << std::setw(97) << "|                                                                        |\n";
    passwordMatch();

    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
}

void MainMenu::registerHandler() {
    drawRegister();

    if (RegisterManager::registerUser(username, password)) {
        std::cout << "User registered successfully!\n";
        sleepMs(1500);
        MainMenu::loginHandler();
    }
    else {
        std::cout << "Registration failed!\n";
    }
}

void MainMenu::displayUserMenu() {
#ifdef _WIN64
    system("cls");
#elif __APPLE__
    system("clear");
#endif
    drawTeamName();

    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                MAIN MENU                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "|                           1. Create Event                              |\n";
    std::cout << std::setw(97) << "|                           2. Browse Events                             |\n";
    std::cout << std::setw(97) << "|                           3. Logout                                    |\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(60) << "Enter your choice: ";

    std::cin >> choice;

    switch (choice) {
    case 1:
        createEventHandler();
        break;
    case 2:
        browseEventsHandler();
        break;
    case 3:
#ifdef _WIN64
        system("cls");
#elif __APPLE__
            system("clear");
#endif
        displayMainMenu();
        break;
    default:
        std::cout << "Invalid input. Please try again!\n";
        sleepMs(1500);
        displayUserMenu();
        break;
    }
}

void MainMenu::createEventHandler() {
#ifdef _WIN64
    system("cls");
#elif __APPLE__
    system("clear");
#endif
    drawTeamName();
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                             CREATE EVENT                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

    EventManager::createEvent();

    system("pause");
    displayUserMenu();
}

void MainMenu::browseEventsHandler() {
#ifdef _WIN64
    system("cls");
#elif __APPLE__
    system("clear");
#endif
    drawTeamName();

    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                            BROWSE EVENTS                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

    EventDisplay::displayEvents();

    std::cout << "Enter the title of the event you want more details on (or press Enter to skip): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string selectedTitle;
    std::getline(std::cin, selectedTitle);

    if (!selectedTitle.empty()) {
        EventDisplay::showEventDetailsByTitle(selectedTitle);

        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    displayUserMenu();
}
