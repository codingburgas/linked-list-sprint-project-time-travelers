#pragma once
#include <string>

struct Event {
    std::string title;
    int year;
    std::string description;
    std::string country;
    std::string prerequisite;
    std::string consequence;
    std::string author;
    Event* next = nullptr;
};

class EventManager {
private:
    Event* head;
public:
    EventManager();
    ~EventManager();

    void createEvent();
    void loadEventsFromFile();
    void saveEventsToFile();
    bool updateEvent(const std::string& oldTitle, const Event& updatedEvent, const std::string& username);
    bool deleteEvent(const std::string& title, const std::string& username);
    void clearList();

    Event* getHead() const { return head; }
};