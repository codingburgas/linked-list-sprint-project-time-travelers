#include "login.h"
#include "../../DAL/include/files.h"
#include "../../DAL/include/globals.h"
#include <iomanip>

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
