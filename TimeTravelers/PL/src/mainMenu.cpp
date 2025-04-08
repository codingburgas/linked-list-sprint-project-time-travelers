#include "mainMenu.h"

static void clearScreen() {
#ifdef _WIN64
    system("cls");
#elif __APPLE__
    system("clear");
#endif
}


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
    case 1: loginHandler(); break;
    case 2: registerHandler(); break;
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
    std::cout << std::setw(94) << "        |_| |_|_| |_| |_|\\___|   |_||_|  \\__,_| \\_/ \\___|_|_|\\___|_|  |___/\n";
    std::cout << '\n';
}

void MainMenu::loginHandler() {
    clearScreen();
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
    clearScreen();
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
        loginHandler();
    }
    else {
        std::cout << "Registration failed!\n";
    }
}

void MainMenu::displayUserMenu() {
    clearScreen();
    drawTeamName();

    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                MAIN MENU                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                                                        |\n";
    std::cout << std::setw(97) << "|                           1. Create Event                              |\n";
    std::cout << std::setw(97) << "|                           2. Browse Events                             |\n";
    std::cout << std::setw(97) << "|                           3. Timeline                                  |\n";
    std::cout << std::setw(97) << "|                           4. Logout                                    |\n";
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
        timelineHandler();
        break;
    case 4:
        clearScreen();
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
    clearScreen();
    drawTeamName();
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                             CREATE EVENT                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

    EventManager::createEvent();

    system("pause");
    displayUserMenu();
}

void MainMenu::browseEventsHandler() {
    clearScreen();
    drawTeamName();

    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                            BROWSE EVENTS                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

    int filterChoice = 0;
    std::cout << "How do you want to view events?\n";
    std::cout << "1. View all events\n";
    std::cout << "2. Filter by country\n";
    std::cout << "3. Filter by year range\n";
    std::cout << "4. Filter by era\n";
    std::cout << "Enter your choice (1-4): ";
    std::cin >> filterChoice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (filterChoice) {
    case 1: {
        std::cout << std::endl;
        std::cout << std::endl;
        EventDisplay::displayEvents();
        break;
    }
    case 2: {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Enter the country name: ";
        std::string country;
        std::getline(std::cin, country);
        EventDisplay::displayEventsByCountry(country);
        break;
    }
    case 3: {
        std::cout << std::endl;
        std::cout << std::endl;
        int startYear, endYear;
        std::cout << "Enter start year: ";
        std::cin >> startYear;
        std::cout << "Enter end year: ";
        std::cin >> endYear;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        EventDisplay::displayEventsByYearRange(startYear, endYear);
        break;
    }
    case 4: {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Available eras:\n"
            << "  Ancient (<500)\n"
            << "  Classical (500-999)\n"
            << "  Medieval (1000-1499)\n"
            << "  Renaissance (1500-1699)\n"
            << "  Industrial (1700-1899)\n"
            << "  Modern (1900-1999)\n"
            << "  Contemporary (2000+)\n";
        std::cout << "Enter era: ";
        std::string era;
        std::getline(std::cin, era);
        EventDisplay::displayEventsByEra(era);
        break;
    }
    default:
        std::cout << "Invalid choice. Showing all events.\n";
        EventDisplay::displayEvents();
        break;
    }

    std::cout << "Enter the title of the event you want more details on (or press Enter to skip): ";
    std::string selectedTitle;
    std::getline(std::cin, selectedTitle);

    if (!selectedTitle.empty()) {
        EventDisplay::showEventDetailsByTitle(selectedTitle);

        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    displayUserMenu();
}

void MainMenu::timelineHandler() {
    clearScreen();
    drawTeamName();
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                TIMELINE                                |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

    TimelineDisplay::displayTimeline();

    std::cout << "Press Enter to return to menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    displayUserMenu();
}
