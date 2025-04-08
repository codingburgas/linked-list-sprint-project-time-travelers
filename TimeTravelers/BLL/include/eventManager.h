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
};

class EventManager {
public:
    static void createEvent();
};