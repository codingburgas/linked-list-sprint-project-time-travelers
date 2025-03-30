#include "login.h"
#include "../../DAL/include/files.h"

bool LoginManager::login(const std::string& username, const std::string& password) {
    json users = FileManager::loadJSON("users.json");

    if (users.contains(username) && users[username]["password"] == password) {
        std::cout << "Login successful!" << std::endl;
        return 1;
    }
    else {
        std::cout << "Invalid username or password! Please try again." << std::endl;
        return 0;
    }
}