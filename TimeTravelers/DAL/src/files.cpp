#include "files.h"
#include <fstream>
#include <iostream>

json FileManager::loadJSON(const std::string& filename) {
    std::ifstream file("../data/" + filename);
    json data;

    if (file.is_open()) {
        try {
            file >> data;
        }
        catch (const std::exception& e) {
            std::cout << "Error reading JSON file: " << e.what() << std::endl;
        }
        file.close();
    } else {
        std::cout << "Could not open file: " << filename << std::endl;
    }

    return data;
}

void FileManager::saveJSON(const std::string& filename, const json& data) {
    std::ofstream file("../data/" + filename);

    if (file.is_open()) {
        file << data.dump(4);
        file.close();
    } else {
        std::cout << "Could not open file for writing: " << filename << std::endl;
    }
}