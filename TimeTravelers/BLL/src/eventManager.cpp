#include "BLL.precompile.h"

EventManager::EventManager() : head(nullptr) {
    loadEventsFromFile();  // Load events into memory on startup
}

EventManager::~EventManager() {
    clearList();           // Free all allocated memory
}

// Creates a new event by prompting the user for input, sets the current user as the author, and saves the event.
void EventManager::createEvent() {
    Event* newEvent = new Event;

    // Clear any leftover input from the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Title of the historic event: ";
    std::getline(std::cin, newEvent->title);

    std::cout << "Enter Year: ";
    std::cin >> newEvent->year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Description: ";
    std::getline(std::cin, newEvent->description);

    std::cout << "Enter Country: ";
    std::getline(std::cin, newEvent->country);

    std::cout << "Enter Prerequisite: ";
    std::getline(std::cin, newEvent->prerequisite);

    std::cout << "Enter Consequence: ";
    std::getline(std::cin, newEvent->consequence);

    // Set the event author to the currently logged-in user.
    newEvent->author = currentUsername;
    newEvent->next = nullptr;

    if (!head) {
        head = newEvent;
    }
    else {
        Event* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newEvent;
    }

    saveEventsToFile();

    std::cout << "\nEvent has been saved successfully!\n";
}

void EventManager::loadEventsFromFile() {
    json data = FileManager::loadJSON("events.json");

    if (!data.is_array()) {
        std::cerr << "Warning: events.json is invalid or empty.\n";
        return;
    }

    for (const auto& item : data) {
        Event* newEvent = new Event;
        newEvent->title = item.value("title", "");
        newEvent->year = item.value("year", 0);
        newEvent->description = item.value("description", "");
        newEvent->country = item.value("country", "");
        newEvent->prerequisite = item.value("prerequisite", "");
        newEvent->consequence = item.value("consequence", "");
        newEvent->author = item.value("author", "");
        newEvent->next = nullptr;

        // Append to linked list
        if (!head) {
            head = newEvent;
        }
        else {
            Event* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newEvent;
        }
    }
}

void EventManager::saveEventsToFile() {
    json eventsArray = json::array();
    Event* current = head;

    while (current != nullptr) {
        json e;
        e["title"] = current->title;
        e["year"] = current->year;
        e["description"] = current->description;
        e["country"] = current->country;
        e["prerequisite"] = current->prerequisite;
        e["consequence"] = current->consequence;
        e["author"] = current->author;

        eventsArray.push_back(e);
        current = current->next;
    }

    FileManager::saveJSON("events.json", eventsArray);
}

bool EventManager::updateEvent(const std::string& oldTitle, const Event& updatedEvent, const std::string& username) {
    Event* current = head;

    while (current != nullptr) {
        if (current->title == oldTitle && current->author == username) {
            // Update the event
            current->title = updatedEvent.title;
            current->year = updatedEvent.year;
            current->description = updatedEvent.description;
            current->country = updatedEvent.country;
            current->prerequisite = updatedEvent.prerequisite;
            current->consequence = updatedEvent.consequence;
            current->author = updatedEvent.author;

            saveEventsToFile(); // persist changes
            return true;
        }
        current = current->next;
    }

    return false; // not found
}

bool EventManager::deleteEvent(const std::string& title, const std::string& username) {
    Event* current = head;
    Event* prev = nullptr;

    while (current != nullptr) {
        if (current->title == title && current->author == username) {
            // Found the node to delete
            if (prev == nullptr) {
                // It's the head
                head = current->next;
            }
            else {
                prev->next = current->next;
            }

            delete current;
            saveEventsToFile(); // persist changes
            return true;
        }

        prev = current;
        current = current->next;
    }

    return false; // not found
}


void EventManager::clearList() {
    while (head != nullptr) {
        Event* temp = head;
        head = head->next;
        delete temp;
    }
}
