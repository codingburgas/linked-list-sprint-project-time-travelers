#pragma once
#include <string>

namespace EventDisplay {
    void displayEvents();
    void displayEventsByCountry(const std::string& country);
    void displayEventsByYearRange(int startYear, int endYear);
    void displayEventsByEra(const std::string& era);
    void showEventDetailsByTitle(const std::string& title);
}