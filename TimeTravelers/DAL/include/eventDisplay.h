#pragma once
#include <string>

namespace EventDisplay {
    void displayEvents();
    void showEventDetailsByTitle(const std::string& title);

    void displayEventsByCountry(const std::string& country);
    void displayEventsByYearRange(int startYear, int endYear);
    void displayEventsByEra(const std::string& era);
}