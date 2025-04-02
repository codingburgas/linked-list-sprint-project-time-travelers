#include "userLogs.h"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

json UserLogs::logsData = json();

static const std::string LOGS_FILE_PATH = "../data/userLogs.json";

bool UserLogs::loadUserProgress(const std::string& username) {
    std::ifstream inFile(LOGS_FILE_PATH);
    if (inFile.good()) {
        try {
            inFile >> logsData;
        }
        catch (const json::parse_error& e) {
            
            logsData = json::object();
        }
    }
    else {
        logsData = json::object();
    }
    inFile.close();

    if (!logsData.is_object()) {
        logsData = json::object();
    }
    if (!logsData.contains(username) || !logsData[username].is_object()) {
        logsData[username] = json::object();
    }
    if (!logsData[username].contains("eras") || !logsData[username]["eras"].is_array()) {
        logsData[username]["eras"] = json::array();
    }
    if (!logsData[username].contains("artifacts") || !logsData[username]["artifacts"].is_array()) {
        logsData[username]["artifacts"] = json::array();
    }
    return true;
}

std::string UserLogs::updateUserProgress(const std::string& username, int eventYear) {
    if (!logsData.is_object()) {
        loadUserProgress(username);
    }

    std::string era = determineEra(eventYear);

    if (!logsData.contains(username)) {
        logsData[username] = json::object();
    }
    if (!logsData[username].contains("eras") || !logsData[username]["eras"].is_array()) {
        logsData[username]["eras"] = json::array();
    }
    if (!logsData[username].contains("artifacts") || !logsData[username]["artifacts"].is_array()) {
        logsData[username]["artifacts"] = json::array();
    }

    bool eraAlreadyVisited = false;
    for (const auto& e : logsData[username]["eras"]) {
        if (e.is_string() && e.get<std::string>() == era) {
            eraAlreadyVisited = true;
            break;
        }
    }
    if (!eraAlreadyVisited) {
        logsData[username]["eras"].push_back(era);
        std::string artifact = getArtifactForEra(era);
        logsData[username]["artifacts"].push_back(artifact);
        return artifact;
    }
    return std::string();
}

bool UserLogs::saveUserProgress() {
    std::cout << "Saving user logs to: " << LOGS_FILE_PATH << std::endl;

    std::ofstream outFile(LOGS_FILE_PATH);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open " << LOGS_FILE_PATH << " for writing." << std::endl;
        return false;
    }
    try {
        outFile << logsData.dump(4);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: Failed to write logs to file. " << e.what() << std::endl;
        outFile.close();
        return false;
    }
    outFile.close();
    return true;
}

std::string UserLogs::determineEra(int year) {
    if (year < 500) {
        return "Ancient";
    }
    else if (year < 1000) {
        return "Classical";
    }
    else if (year < 1500) {
        return "Medieval";
    }
    else if (year < 1700) {
        return "Renaissance";
    }
    else if (year < 1900) {
        return "Industrial";
    }
    else if (year < 2000) {
        return "Modern";
    }
    else {
        return "Contemporary";
    }
}

std::string UserLogs::getArtifactForEra(const std::string& era) {
    if (era == "Ancient")       return "Cleopatra's Scroll";
    if (era == "Classical")     return "Charlemagne's Sword";
    if (era == "Medieval")      return "Knight's Shield";
    if (era == "Renaissance")   return "Da Vinci's Sketchbook";
    if (era == "Industrial")    return "Edison's Lightbulb";
    if (era == "Modern")        return "Moon Rock";
    if (era == "Contemporary")  return "Mars Rover Wheel";
    return "Unknown Artifact";
}
