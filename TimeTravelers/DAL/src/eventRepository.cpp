#include "eventRepository.h"
#include "../../DAL/include/files.h"
#include <iostream>

void EventRepository::saveEvent(const Event& event) {

    json eventsArray = FileManager::loadJSON("events.json");

    if (!eventsArray.is_array()) {
        eventsArray = json::array();
    }

    json newEventJson;
    newEventJson["title"]        = event.title;
    newEventJson["year"]         = event.year;
    newEventJson["description"]  = event.description;
    newEventJson["country"]      = event.country;
    newEventJson["prerequisite"] = event.prerequisite;
    newEventJson["consequence"]  = event.consequence;

    eventsArray.push_back(newEventJson);

    FileManager::saveJSON("events.json", eventsArray);
}