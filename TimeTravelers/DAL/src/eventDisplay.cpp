#include "eventDisplay.h"
#include "files.h"
#include "json.hpp"
#include "userLogs.h"
#include "globals.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using json = nlohmann::json;

namespace EventDisplay {

    void displayEvents() {
        json data = FileManager::loadJSON("events.json");

        if (!data.is_array()) {
            std::cerr << "Error: events.json is not a valid array or could not be loaded.\n";
            return;
        }

        for (const auto& event : data) {
            std::string title = event.value("title", "<Unknown>");
            int year = event.value("year", 0);
            std::string country = event.value("country", "<Unknown>");

            std::string yearStr = (year == 0) ? "Unknown" : std::to_string(year);

            std::string titleLine = "Title: " + title;
            std::string yearLine = "Year: " + yearStr;
            std::string countryLine = "Country: " + country;

            size_t maxLen = std::max({ titleLine.size(), yearLine.size(), countryLine.size() });

            std::string border = "+" + std::string(maxLen + 2, '-') + "+";

            std::cout << border << std::endl;

            auto printLine = [&](const std::string& line) {
                std::cout << "| " << line
                    << std::string(maxLen - line.size(), ' ')
                    << " |" << std::endl;
                };

            printLine(titleLine);
            printLine(yearLine);
            printLine(countryLine);

            std::cout << border << std::endl << std::endl;
        }

        if (data.empty()) {
            std::cout << "No events found in events.json.\n";
        }
    }

    void showEventDetailsByTitle(const std::string& title) {
        json data = FileManager::loadJSON("events.json");
        if (!data.is_array()) {
            std::cerr << "Error: events.json is not a valid array or could not be loaded.\n";
            return;
        }

        bool found = false;
        for (auto& event : data) {
            std::string eventTitle = event.value("title", "");
            if (eventTitle == title) {
                found = true;

                int year = event.value("year", 0);
                std::string yearStr = (year == 0) ? "Unknown" : std::to_string(year);

                std::string country = event.value("country", "<Unknown>");
                std::string description = event.value("description", "<Unknown>");
                std::string prerequisite = event.value("prerequisite", "<Unknown>");
                std::string consequence = event.value("consequence", "<Unknown>");

                std::cout << "\n===== Event Details =====\n";
                std::cout << "Title:         " << eventTitle << std::endl;
                std::cout << "Year:          " << yearStr << std::endl;
                std::cout << "Country:       " << country << std::endl;
                std::cout << "Description:   " << description << std::endl;
                std::cout << "Prerequisite:  " << prerequisite << std::endl;
                std::cout << "Consequence:   " << consequence << std::endl;
                std::cout << "=========================\n\n";

                std::string unlockedArtifact = UserLogs::updateUserProgress(currentUsername, year);
                if (!unlockedArtifact.empty()) {
                    std::cout << "Achievement Unlocked: " << unlockedArtifact << "!" << std::endl;
                    UserLogs::saveUserProgress();
                }
                break;
            }
        }

        if (!found) {
            std::cout << "Event not found with title: " << title << std::endl;
        }
    }

}
