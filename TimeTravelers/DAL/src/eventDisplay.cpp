#include "eventDisplay.h"
#include "files.h"
#include "userLogs.h"
#include "globals.h"
#include "DAL.precompile.h"

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

    //Displaying all the events
    void displayEvents(EventManager& manager) {
        Event* current = manager.getHead();
        if (!current) {
            std::cout << "No events found.\n";
            return;
        }

        while (current) {
            std::string titleLine = "Title: " + current->title;
            std::string yearLine = "Year: " + (current->year == 0 ? "Unknown" : std::to_string(current->year));
            std::string countryLine = "Country: " + current->country;

            size_t maxLen = std::max({ titleLine.size(), yearLine.size(), countryLine.size() });
            std::string border = "+" + std::string(maxLen + 2, '-') + "+";

            auto printLine = [&](const std::string& line) {
                std::cout << "| " << line << std::string(maxLen - line.size(), ' ') << " |" << std::endl;
                };

            std::cout << border << std::endl;
            printLine(titleLine);
            printLine(yearLine);
            printLine(countryLine);
            std::cout << border << "\n\n";

            current = current->next;
        }
    }

    void displayEventsByCountry(EventManager& manager, const std::string& countryFilter) {
        Event* current = manager.getHead();
        bool found = false;

        while (current) {
            if (current->country == countryFilter) {
                found = true;

                std::string titleLine = "Title: " + current->title;
                std::string yearLine = "Year: " + (current->year == 0 ? "Unknown" : std::to_string(current->year));
                std::string countryLine = "Country: " + current->country;

                size_t maxLen = std::max({ titleLine.size(), yearLine.size(), countryLine.size() });
                std::string border = "+" + std::string(maxLen + 2, '-') + "+";

                auto printLine = [&](const std::string& line) {
                    std::cout << "| " << line << std::string(maxLen - line.size(), ' ') << " |" << std::endl;
                    };

                std::cout << border << std::endl;
                printLine(titleLine);
                printLine(yearLine);
                printLine(countryLine);
                std::cout << border << "\n\n";
            }
            current = current->next;
        }

        if (!found) {
            std::cout << "No events found for country: " << countryFilter << std::endl;
        }
    }

    void displayEventsByYearRange(EventManager& manager, int startYear, int endYear) {
        if (startYear > endYear) {
            std::cout << "Invalid range: " << startYear << " > " << endYear << std::endl;
            return;
        }

        Event* current = manager.getHead();
        bool found = false;

        while (current) {
            if (current->year >= startYear && current->year <= endYear) {
                found = true;

                std::string titleLine = "Title: " + current->title;
                std::string yearLine = "Year: " + std::to_string(current->year);
                std::string countryLine = "Country: " + current->country;

                size_t maxLen = std::max({ titleLine.size(), yearLine.size(), countryLine.size() });
                std::string border = "+" + std::string(maxLen + 2, '-') + "+";

                auto printLine = [&](const std::string& line) {
                    std::cout << "| " << line << std::string(maxLen - line.size(), ' ') << " |" << std::endl;
                    };

                std::cout << border << std::endl;
                printLine(titleLine);
                printLine(yearLine);
                printLine(countryLine);
                std::cout << border << "\n\n";
            }
            current = current->next;
        }

        if (!found) {
            std::cout << "No events found in the range " << startYear << " - " << endYear << std::endl;
        }
    }

    void displayEventsByEra(EventManager& manager, const std::string& eraFilter) {
        Event* current = manager.getHead();
        bool found = false;

        while (current) {
            if (determineEra(current->year) == eraFilter) {
                found = true;

                std::string titleLine = "Title: " + current->title;
                std::string yearLine = "Year: " + std::to_string(current->year);
                std::string countryLine = "Country: " + current->country;

                size_t maxLen = std::max({ titleLine.size(), yearLine.size(), countryLine.size() });
                std::string border = "+" + std::string(maxLen + 2, '-') + "+";

                auto printLine = [&](const std::string& line) {
                    std::cout << "| " << line << std::string(maxLen - line.size(), ' ') << " |" << std::endl;
                    };

                std::cout << border << std::endl;
                printLine(titleLine);
                printLine(yearLine);
                printLine(countryLine);
                std::cout << border << "\n\n";
            }
            current = current->next;
        }

        if (!found) {
            std::cout << "No events found for era: " << eraFilter << std::endl;
        }
    }

    void displayEventsByTitleKeyword(EventManager& manager, const std::string& keyword) {
        Event* current = manager.getHead();
        bool found = false;

        while (current) {
            if (current->title.find(keyword) != std::string::npos) {
                found = true;

                std::string titleLine = "Title: " + current->title;
                std::string yearLine = "Year: " + std::to_string(current->year);
                std::string countryLine = "Country: " + current->country;

                size_t maxLen = std::max({ titleLine.size(), yearLine.size(), countryLine.size() });
                std::string border = "+" + std::string(maxLen + 2, '-') + "+";

                auto printLine = [&](const std::string& line) {
                    std::cout << "| " << line << std::string(maxLen - line.size(), ' ') << " |" << std::endl;
                    };

                std::cout << border << std::endl;
                printLine(titleLine);
                printLine(yearLine);
                printLine(countryLine);
                std::cout << border << "\n\n";
            }
            current = current->next;
        }

        if (!found) {
            std::cout << "No events found with keyword: " << keyword << std::endl;
        }
    }

    void showEventDetailsByTitle(EventManager& manager, const std::string& title) {
        Event* current = manager.getHead();
        while (current) {
            if (current->title == title) {
                std::cout << "\n===== Event Details =====\n";
                std::cout << "Title:         " << current->title << "\n";
                std::cout << "Year:          " << current->year << "\n";
                std::cout << "Country:       " << current->country << "\n";
                std::cout << "Description:   " << current->description << "\n";
                std::cout << "Prerequisite:  " << current->prerequisite << "\n";
                std::cout << "Consequence:   " << current->consequence << "\n";
                std::cout << "Author:        " << current->author << "\n";
                std::cout << "=========================\n\n";

                std::string unlocked = UserLogs::updateUserProgress(currentUsername, current->year);
                if (!unlocked.empty()) {
                    std::cout << "Achievement Unlocked: " << unlocked << "!\n";
                    UserLogs::saveUserProgress();
                }

                if (current->author == currentUsername) {
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
                        Event updated = *current;

                        std::cout << "Enter new title (or press Enter to keep '" << current->title << "'): ";
                        std::string input;
                        std::getline(std::cin, input);
                        if (!input.empty()) updated.title = input;

                        std::cout << "Enter new year (or 0 to keep " << current->year << "): ";
                        int newYear;
                        std::cin >> newYear;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if (newYear != 0) updated.year = newYear;

                        std::cout << "Enter new description (or press Enter to keep current): ";
                        std::getline(std::cin, input);
                        if (!input.empty()) updated.description = input;

                        std::cout << "Enter new country (or press Enter to keep current): ";
                        std::getline(std::cin, input);
                        if (!input.empty()) updated.country = input;

                        std::cout << "Enter new prerequisite (or press Enter to keep current): ";
                        std::getline(std::cin, input);
                        if (!input.empty()) updated.prerequisite = input;

                        std::cout << "Enter new consequence (or press Enter to keep current): ";
                        std::getline(std::cin, input);
                        if (!input.empty()) updated.consequence = input;

                        if (manager.updateEvent(current->title, updated, currentUsername)) {
                            std::cout << "Event updated successfully!\n";
                        }
                        else {
                            std::cout << "Failed to update event.\n";
                        }

                    }
                    else if (choice == 2) {
                        if (manager.deleteEvent(current->title, currentUsername)) {
                            std::cout << "Event deleted successfully!\n";
                        }
                        else {
                            std::cout << "Failed to delete event.\n";
                        }
                    }
                    else {
                        std::cout << "No changes made.\n";
                    }
                }
                return;
            }
            current = current->next;
        }

        std::cout << "Event not found with title: " << title << "\n";
    }

}