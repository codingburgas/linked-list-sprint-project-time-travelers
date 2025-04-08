#pragma once
#include "../../BLL/include/eventManager.h"

class EventRepository {
public:
    static void saveEvent(const Event& event);
    static bool updateEvent(const std::string& oldTitle, const Event& updatedEvent, const std::string& username);
    static bool deleteEvent(const std::string& title, const std::string& username);
};