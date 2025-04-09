#pragma once
#include <string>
#include "../../BLL/include/eventManager.h"

namespace EventDisplay {
    void displayEvents(EventManager& manager);
    void displayEventsByCountry(EventManager& manager, const std::string& countryFilter);
    void displayEventsByYearRange(EventManager& manager, int startYear, int endYear);
    void displayEventsByEra(EventManager& manager, const std::string& eraFilter);
    void displayEventsByTitleKeyword(EventManager& manager, const std::string& keyword);
    void showEventDetailsByTitle(EventManager& manager, const std::string& title);
}