#pragma once
#include <string>

class ReportManager {
public:
    static void listAllEventTitles();

    static void listEventsByTopic(const std::string& keyword);

    static void listVictoryForBulgaria();
};