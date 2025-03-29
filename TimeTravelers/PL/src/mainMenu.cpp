#include "mainMenu.h"

void MainMenu::displayMainMenu() {
    std::cout << "  TTTTT  III  M   M  EEEEE      TTTTT  RRRR   AAAAA  V   V  EEEEE  L      EEEEE  RRRR   SSS  " << std::endl;
    std::cout << "    T     I   MM MM  E           T    R   R  A   A  V   V  E      L      E      R   R  S    " << std::endl;
    std::cout << "    T     I   M M M  EEEE        T    RRRR   AAAAA  V   V  EEEE   L      EEEE   RRRR    SSS " << std::endl;
    std::cout << "    T     I   M   M  E           T    R  R   A   A   V V   E      L      E      R  R       S" << std::endl;
    std::cout << "    T    III  M   M  EEEEE        T    R   R  A   A    V    EEEEE  LLLLL  EEEEE  R   R  SSS  " << std::endl;

    std::cout << "1. Login\n";
    std::cout << "2. Register\n";
    std::cout << "3. Exit\n";

    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: std::cout << " " << std::endl;
    case 2: MainMenu::registerHandler();
    case 3: break;
    default: std::cout << "Invalid input!\n"; return;
    }
}

void MainMenu::loginHandler() {
    std::cout << '\n';
}

void MainMenu::registerHandler() {
    system("cls");
      std::cout << "Enter your email: ";
      std::cin >> email;   
      std::cout << "\nEnter your username: ";
      std::cin >> userName;
      std::cout << "\nEnter your password: ";
      std::cin >> password;
      std::cout << "\nConfirm password: ";
      std::cin >> confirmPass;
}