#include "BLL.precompile.h"

// Handles the registration of a new user
bool RegisterManager::registerUser(const std::string& username, const std::string& password) {
    json users = FileManager::loadJSON("users.json");

    if (users.contains(username)) {
        std::cout << "User already exists! Please try with different information." << std::endl;
        return false;
    }

    users[username] = {
        {"password", password}
    };

    FileManager::saveJSON("users.json", users);
    return true;
}