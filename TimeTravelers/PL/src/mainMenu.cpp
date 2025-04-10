#include "mainMenu.h"

// Clears the console screen (cross-platform)
static void clearScreen() {
#ifdef _WIN64
    system("cls");
#elif __APPLE__
    system("clear");
#endif
}


//Displays the main menu before logging in
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

//Displays the team name
void MainMenu::drawTeamName() {
    std::cout << std::setw(94) << "       _____ _                  _____                    _ _               \n";
    std::cout << std::setw(94) << "      |_   _(_)_ __ ___   ___  |_   _| __ __ ___   _____| | | ___ _ __ ___ \n";
    std::cout << std::setw(94) << "        | | | | '_ ` _ \\ / _ \\   | || '__/ _` \\ \\ / / _ \\ | |/ _ \\ '__/ __|\n";
    std::cout << std::setw(94) << "        | | | | | | | | |  __/   | || | | (_| |\\ V /  __/ | |  __/ |  \\__ \\\n";
    std::cout << std::setw(94) << "        |_| |_|_| |_| |_|\\___|   |_||_|  \\__,_| \\_/ \\___|_|_|\\___|_|  |___/\n";
    std::cout << '\n';
}

//Displays the login menu
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

//Displays the register menu
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

//Displays the main menu after logging in
void MainMenu::displayUserMenu() {
    clearScreen();
    drawTeamName();

    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                MAIN MENU                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                           1. Create Event                              |\n";
    std::cout << std::setw(97) << "|                           2. Browse Events                             |\n";
    std::cout << std::setw(97) << "|                           3. Timeline                                  |\n";
    std::cout << std::setw(97) << "|                           4. AI Chat                                   |\n";
    std::cout << std::setw(97) << "|                           5. Reports                                   |\n";
    std::cout << std::setw(97) << "|                           6. Logout                                    |\n";
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
        AIchat::startChat();
        displayUserMenu();
        break;
    case 5:
        reportMenuHandler();
        break;
    case 6:
        clearScreen();
        displayMainMenu();
    default:
        std::cout << "Invalid input. Please try again!\n";
        sleepMs(1500);
        displayUserMenu();
        break;
    }
}

//Displays create event winwow
void MainMenu::createEventHandler() {
    clearScreen();
    drawTeamName();
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                             CREATE EVENT                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

    manager.createEvent();

    system("pause");
    displayUserMenu();
}

//Displays browse events window
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
    std::cout << "5. Search by title keyword\n";
    std::cout << "Enter your choice (1-5): ";
    std::cin >> filterChoice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (filterChoice) {
    case 1: {
        std::cout << "\n\n";
        EventDisplay::displayEvents(manager);
        break;
    }
    case 2: {
        std::cout << "\nEnter the country name: ";
        std::string country;
        std::getline(std::cin, country);
        EventDisplay::displayEventsByCountry(manager, country);
        break;
    }
    case 3: {
        int startYear, endYear;
        std::cout << "\nEnter start year: ";
        std::cin >> startYear;
        std::cout << "Enter end year: ";
        std::cin >> endYear;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        EventDisplay::displayEventsByYearRange(manager, startYear, endYear);
        break;
    }
    case 4: {
        std::cout << "\nAvailable eras:\n"
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
        EventDisplay::displayEventsByEra(manager, era);
        break;
    }
    case 5: {
        std::cout << "\nEnter title keyword to search for: ";
        std::string keyword;
        std::getline(std::cin, keyword);
        EventDisplay::displayEventsByTitleKeyword(manager, keyword);
        break;
    }
    default:
        std::cout << "Invalid choice. Showing all events.\n";
        EventDisplay::displayEvents(manager);
        break;
    }

    std::cout << "\nEnter the title of the event you want more details on (or press Enter to skip): ";
    std::string selectedTitle;
    std::getline(std::cin, selectedTitle);

    if (!selectedTitle.empty()) {
        EventDisplay::showEventDetailsByTitle(manager, selectedTitle);
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    displayUserMenu();
}


//Displays the timeline of the events
void MainMenu::timelineHandler() {
    clearScreen();
    drawTeamName();
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                TIMELINE                                |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

    TimelineDisplay::displayTimeline(manager);

    std::cout << "Press Enter to return to menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    displayUserMenu();
}


//Displays the AI chat window
void MainMenu::aiChatHandler() {
    clearScreen();
    drawTeamName();
    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                                AI CHAT                                 |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

    AIchat::startChat();

    std::cout << "Press Enter to return to menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    displayUserMenu();
}

void MainMenu::reportMenuHandler() {
    clearScreen();
    drawTeamName();

    std::cout << std::setw(97) << "==========================================================================\n";
    std::cout << std::setw(97) << "|                              REPORT MENU                               |\n";
    std::cout << std::setw(97) << "==========================================================================\n";

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "      1) Report all event titles\n";
    std::cout << "      2) Report events by a certain topic\n";
    std::cout << "      3) Report events that ended in victory for Bulgaria\n";
    std::cout << "      4) Back to main menu\n";
    std::cout << "      Enter your choice: ";
    int reportChoice;
    std::cin >> reportChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (reportChoice) {
    case 1: {
        ReportManager::listAllEventTitles();
        system("pause");
        break;
    }
    case 2: {
        std::cout << "Enter topic keyword: ";
        std::string topic;
        std::getline(std::cin, topic);
        ReportManager::listEventsByTopic(topic);
        system("pause");
        break;
    }
    case 3: {
        ReportManager::listVictoryForBulgaria();
        system("pause");
        break;
    }
    default:
        break;
    }

    displayUserMenu();
}
