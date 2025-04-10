#include "reportManager.h"
#include "../../DAL/include/files.h"
#include "../../DAL/include/globals.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using json = nlohmann::json;

namespace {

    struct SimpleEvent {
        std::string title;
        std::string description;
        std::string country;
        std::string consequence;
        int year;
    };

    std::vector<SimpleEvent> loadAllEvents() {
        std::vector<SimpleEvent> events;
        json data = FileManager::loadJSON("events.json");
        if (!data.is_array()) {
            std::cerr << "Error: events.json is not valid or not an array.\n";
            return events;
        }
        for (auto& e : data) {
            SimpleEvent ev;
            ev.title = e.value("title", "<Unknown>");
            ev.description = e.value("description", "<No Description>");
            ev.country = e.value("country", "<No Country>");
            ev.consequence = e.value("consequence", "");
            ev.year = e.value("year", 0);
            events.push_back(ev);
        }
        return events;
    }
}

void ReportManager::listAllEventTitles() {
    std::vector<SimpleEvent> allEvents = loadAllEvents();
    if (allEvents.empty()) {
        std::cout << "No events found.\n";
        return;
    }
    std::cout << std::endl;
    std::cout << std::setw(77) << "===== List of All Event Titles =====\n";
    std::cout << std::endl;
    for (auto& ev : allEvents) {
        std::cout << "- " << ev.title << " (" << ev.year << ")\n";
    }
    std::cout << std::endl;
}

void ReportManager::listEventsByTopic(const std::string& keyword) {
    std::vector<SimpleEvent> allEvents = loadAllEvents();
    if (allEvents.empty()) {
        std::cout << "      No events found.\n";
        return;
    }

    bool anyFound = false;
    std::cout << std::endl;
    std::cout << std::setw(67) << "===== Events Matching Topic: \"" << keyword << "\" =====\n";
    std::cout << std::endl;
    for (auto& ev : allEvents) {

        if (ev.title.find(keyword) != std::string::npos ||
            ev.description.find(keyword) != std::string::npos)
        {
            anyFound = true;
            std::cout << "      - " << ev.title << " (" << ev.year << ") in " << ev.country << "\n";
            std::cout << "        Description: " << ev.description << "\n\n";
        }
    }
    if (!anyFound) {
        std::cout << "      No events found for topic \"" << keyword << "\".\n";
    }
    std::cout << std::endl;
}

void ReportManager::listVictoryForBulgaria() {
    std::vector<SimpleEvent> allEvents = loadAllEvents();
    if (allEvents.empty()) {
        std::cout << "      No events found.\n";
        return;
    }

    bool anyFound = false;
    std::cout << std::endl;
    std::cout << std::setw(80) << "===== Events That Ended in Victory for Bulgaria =====\n";
    std::cout << std::endl;
    for (auto& ev : allEvents) {
        if ((ev.country == "Bulgaria") &&
            (ev.consequence.find("victory") != std::string::npos ||
                ev.consequence.find("Victory") != std::string::npos))
        {
            anyFound = true;
            std::cout <<  "      - " << ev.title << " (" << ev.year << ")\n";
            std::cout << "        Consequence: " << ev.consequence << "\n\n";
        }
    }
    if (!anyFound) {
        std::cout << "      No events ended in victory for Bulgaria.\n";
    }
    std::cout << std::endl;
}