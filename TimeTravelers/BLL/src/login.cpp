#include "BLL.precompile.h"

// Logs in a user by checking the provided username and password with the stored in the JSON file
bool LoginManager::login(const std::string& username, const std::string& password) {
    json users = FileManager::loadJSON("users.json");

    if (users.contains(username) && users[username]["password"] == password) {
        currentUsername = username;
        std::cout << std::setw(97) << "Login successful!" << std::endl;
        return true;
    }
    else {
        std::cout << "Invalid username or password! Please try again." << std::endl;
        return false;
    }
}
