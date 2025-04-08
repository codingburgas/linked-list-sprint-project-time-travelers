#include "eventRepository.h"
#include "../../DAL/include/files.h"
#include <iostream>

using json = nlohmann::json;

void EventRepository::saveEvent(const Event& event) {
    json eventsArray = FileManager::loadJSON("events.json");

    if (!eventsArray.is_array()) {
        eventsArray = json::array();
    }

    json newEventJson;
    newEventJson["title"] = event.title;
    newEventJson["year"] = event.year;
    newEventJson["description"] = event.description;
    newEventJson["country"] = event.country;
    newEventJson["prerequisite"] = event.prerequisite;
    newEventJson["consequence"] = event.consequence;
    newEventJson["author"] = event.author;

    eventsArray.push_back(newEventJson);

    FileManager::saveJSON("events.json", eventsArray);
}

bool EventRepository::updateEvent(const std::string& oldTitle, const Event& updatedEvent, const std::string& username) {
    json eventsArray = FileManager::loadJSON("events.json");
    if (!eventsArray.is_array()) {
        std::cerr << "events.json is not an array. Cannot update.\n";
        return false;
    }

    bool found = false;
    for (auto& e : eventsArray) {
        std::string existingTitle = e.value("title", "");
        std::string existingAuthor = e.value("author", "");
        if (existingTitle == oldTitle && existingAuthor == username) {
            e["title"] = updatedEvent.title;
            e["year"] = updatedEvent.year;
            e["description"] = updatedEvent.description;
            e["country"] = updatedEvent.country;
            e["prerequisite"] = updatedEvent.prerequisite;
            e["consequence"] = updatedEvent.consequence;
            e["author"] = updatedEvent.author;
            found = true;
            break;
        }
    }

    if (found) {
        FileManager::saveJSON("events.json", eventsArray);
    }
    return found;
}

bool EventRepository::deleteEvent(const std::string& title, const std::string& username) {
    json eventsArray = FileManager::loadJSON("events.json");
    if (!eventsArray.is_array()) {
        std::cerr << "events.json is not an array. Cannot delete.\n";
        return false;
    }

    bool found = false;
    for (auto it = eventsArray.begin(); it != eventsArray.end(); ++it) {
        std::string existingTitle = it->value("title", "");
        std::string existingAuthor = it->value("author", "");
        if (existingTitle == title && existingAuthor == username) {
            eventsArray.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        FileManager::saveJSON("events.json", eventsArray);
    }
    return found;
}