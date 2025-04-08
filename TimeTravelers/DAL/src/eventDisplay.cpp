#include "eventDisplay.h"
#include "files.h"
#include "json.hpp"
#include "userLogs.h"
#include "globals.h"
#include "../../DAL/include/eventRepository.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>

using json = nlohmann::json;

namespace EventDisplay {

    static std::string determineEra(int year) {
        if (year < 500)             return "Ancient";
        else if (year < 1000)       return "Classical";
        else if (year < 1500)       return "Medieval";
        else if (year < 1700)       return "Renaissance";
        else if (year < 1900)       return "Industrial";
        else if (year < 2000)       return "Modern";
        else                        return "Contemporary";
    }

    void displayEvents() {
        json data = FileManager::loadJSON("events.json");
        if (!data.is_array()) {
            std::cerr << "Error: events.json is not valid.\n";
            return;
        }
        if (data.empty()) {
            std::cout << "No events found.\n";
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
                std::cout << "| " << line << std::string(maxLen - line.size(), ' ') << " |" << std::endl;
                };
            printLine(titleLine);
            printLine(yearLine);
            printLine(countryLine);
            std::cout << border << std::endl << std::endl;
        }
    }

    void displayEventsByCountry(const std::string& countryFilter) {
        json data = FileManager::loadJSON("events.json");
        if (!data.is_array()) {
            std::cerr << "Error: events.json is not valid.\n";
            return;
        }
        bool anyFound = false;
        for (const auto& event : data) {

            std::string title = event.value("title", "<Unknown>");

            int year = event.value("year", 0);

            std::string country = event.value("country", "<Unknown>");

            if (country == countryFilter) {
                anyFound = true;

                std::string yearStr = (year == 0) ? "Unknown" : std::to_string(year);
                std::string titleLine = "Title: " + title;
                std::string yearLine = "Year: " + yearStr;
                std::string countryLine = "Country: " + country;

                size_t maxLen = std::max({ titleLine.size(), yearLine.size(), countryLine.size() });

                std::string border = "+" + std::string(maxLen + 2, '-') + "+";
                std::cout << border << std::endl;

                auto printLine = [&](const std::string& line) {
                    std::cout << "| " << line << std::string(maxLen - line.size(), ' ') << " |" << std::endl;
                    };

                printLine(titleLine);
                printLine(yearLine);
                printLine(countryLine);

                std::cout << border << std::endl << std::endl;
            }
        }
        if (!anyFound) {
            std::cout << "No events found for country: " << countryFilter << std::endl;
        }
    }

    void displayEventsByYearRange(int startYear, int endYear) {
        json data = FileManager::loadJSON("events.json");
        if (!data.is_array()) {
            std::cerr << "Error: events.json is not valid.\n";
            return;
        }
        if (startYear > endYear) {
            std::cerr << "Invalid range: " << startYear << " > " << endYear << std::endl;
            return;
        }
        bool anyFound = false;
        for (const auto& event : data) {

            std::string title = event.value("title", "<Unknown>");

            int year = event.value("year", 0);

            std::string country = event.value("country", "<Unknown>");

            if (year >= startYear && year <= endYear) {
                anyFound = true;

                std::string yearStr = (year == 0) ? "Unknown" : std::to_string(year);
                std::string titleLine = "Title: " + title;
                std::string yearLine = "Year: " + yearStr;
                std::string countryLine = "Country: " + country;

                size_t maxLen = std::max({ titleLine.size(), yearLine.size(), countryLine.size() });

                std::string border = "+" + std::string(maxLen + 2, '-') + "+";

                std::cout << border << std::endl;

                auto printLine = [&](const std::string& line) {
                    std::cout << "| " << line << std::string(maxLen - line.size(), ' ') << " |" << std::endl;
                    };

                printLine(titleLine);
                printLine(yearLine);
                printLine(countryLine);

                std::cout << border << std::endl << std::endl;
            }
        }
        if (!anyFound) {
            std::cout << "No events found in the range " << startYear << "-" << endYear << std::endl;
        }
    }

    void displayEventsByEra(const std::string& eraFilter) {
        json data = FileManager::loadJSON("events.json");
        if (!data.is_array()) {
            std::cerr << "Error: events.json is not valid.\n";
            return;
        }
        bool anyFound = false;
        for (const auto& event : data) {

            std::string title = event.value("title", "<Unknown>");

            int year = event.value("year", 0);

            std::string country = event.value("country", "<Unknown>");
            std::string eventEra = determineEra(year);

            if (eventEra == eraFilter) {
                anyFound = true;

                std::string yearStr = (year == 0) ? "Unknown" : std::to_string(year);
                std::string titleLine = "Title: " + title;
                std::string yearLine = "Year: " + yearStr;
                std::string countryLine = "Country: " + country;

                size_t maxLen = std::max({ titleLine.size(), yearLine.size(), countryLine.size() });

                std::string border = "+" + std::string(maxLen + 2, '-') + "+";
                std::cout << border << std::endl;

                auto printLine = [&](const std::string& line) {
                    std::cout << "| " << line << std::string(maxLen - line.size(), ' ') << " |" << std::endl;
                    };

                printLine(titleLine);
                printLine(yearLine);
                printLine(countryLine);

                std::cout << border << std::endl << std::endl;
            }
        }
        if (!anyFound) {
            std::cout << "No events found for era: " << eraFilter << std::endl;
        }
    }

    void showEventDetailsByTitle(const std::string& title) {
        json data = FileManager::loadJSON("events.json");
        if (!data.is_array()) {
            std::cerr << "Error: events.json is not valid.\n";
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
                std::string author = event.value("author", "<Unknown>");

                std::cout << "\n===== Event Details =====\n";
                std::cout << "Title:         " << eventTitle << std::endl;
                std::cout << "Year:          " << yearStr << std::endl;
                std::cout << "Country:       " << country << std::endl;
                std::cout << "Description:   " << description << std::endl;
                std::cout << "Prerequisite:  " << prerequisite << std::endl;
                std::cout << "Consequence:   " << consequence << std::endl;
                std::cout << "Author:        " << author << std::endl;
                std::cout << "=========================\n\n";

                std::string unlockedArtifact = UserLogs::updateUserProgress(currentUsername, year);
                if (!unlockedArtifact.empty()) {
                    std::cout << "Achievement Unlocked: " << unlockedArtifact << "!" << std::endl;
                    UserLogs::saveUserProgress();
                }

                if (author == currentUsername) {
                    std::cout << "You are the author of this event.\n";
                    std::cout << "Do you want to:\n";
                    std::cout << "  1) Edit the event\n";
                    std::cout << "  2) Delete the event\n";
                    std::cout << "  3) Cancel\n";
                    std::cout << "Enter your choice: ";
                    int choice;
                    std::cin >> choice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (choice == 1) {
                        Event updatedEvent;
                        updatedEvent.author = currentUsername;

                        std::cout << "Enter new title (or press Enter to keep '" << eventTitle << "'): ";
                        std::string newTitle;
                        std::getline(std::cin, newTitle);
                        updatedEvent.title = (newTitle.empty()) ? eventTitle : newTitle;

                        std::cout << "Enter new year (or 0 to keep " << year << "): ";
                        int newYear;
                        std::cin >> newYear;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        updatedEvent.year = (newYear == 0) ? year : newYear;

                        std::cout << "Enter new description (or press Enter to keep current): ";
                        std::string newDesc;
                        std::getline(std::cin, newDesc);
                        updatedEvent.description = (newDesc.empty()) ? description : newDesc;

                        std::cout << "Enter new country (or press Enter to keep current): ";
                        std::string newCountry;
                        std::getline(std::cin, newCountry);
                        updatedEvent.country = (newCountry.empty()) ? country : newCountry;

                        std::cout << "Enter new prerequisite (or press Enter to keep current): ";
                        std::string newPrereq;
                        std::getline(std::cin, newPrereq);
                        updatedEvent.prerequisite = (newPrereq.empty()) ? prerequisite : newPrereq;

                        std::cout << "Enter new consequence (or press Enter to keep current): ";
                        std::string newConseq;
                        std::getline(std::cin, newConseq);
                        updatedEvent.consequence = (newConseq.empty()) ? consequence : newConseq;

                        bool success = EventRepository::updateEvent(eventTitle, updatedEvent, currentUsername);
                        if (success) {
                            std::cout << "Event updated successfully!\n";
                        }
                        else {
                            std::cout << "Error: Could not update event.\n";
                        }
                    }
                    else if (choice == 2) {
                        bool success = EventRepository::deleteEvent(eventTitle, currentUsername);
                        if (success) {
                            std::cout << "Event deleted successfully!\n";
                        }
                        else {
                            std::cout << "Error: Could not delete event.\n";
                        }
                    }
                    else {
                        std::cout << "No changes made.\n";
                    }
                }
                break;
            }
        }
        if (!found) {
            std::cout << "Event not found with title: " << title << std::endl;
        }
    }

}