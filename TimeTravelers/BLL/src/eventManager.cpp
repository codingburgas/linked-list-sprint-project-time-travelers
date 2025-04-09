#include "BLL.precompile.h"

// Creates a new event by prompting the user for input, sets the current user as the author, and saves the event.
void EventManager::createEvent() {
    Event newEvent;

    // Clear any leftover input from the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Title of the historic event: ";
    std::getline(std::cin, newEvent.title);

    std::cout << "Enter Year: ";
    std::cin >> newEvent.year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Description: ";
    std::getline(std::cin, newEvent.description);

    std::cout << "Enter Country: ";
    std::getline(std::cin, newEvent.country);

    std::cout << "Enter Prerequisite: ";
    std::getline(std::cin, newEvent.prerequisite);

    std::cout << "Enter Consequence: ";
    std::getline(std::cin, newEvent.consequence);

    // Set the event author to the currently logged-in user.
    newEvent.author = currentUsername;

    EventRepository::saveEvent(newEvent);

    std::cout << "\nEvent has been saved successfully!\n";
}