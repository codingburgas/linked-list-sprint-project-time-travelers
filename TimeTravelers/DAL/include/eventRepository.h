#pragma once
#include "../../BLL/include/eventManager.h"

class EventRepository {
public:
    static void saveEvent(const Event& event);
};