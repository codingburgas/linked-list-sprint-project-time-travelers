#include "timelineDisplay.h"
#include "files.h"
#include "json.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using json = nlohmann::json;

namespace TimelineDisplay {

    struct TimelineEvent {
        int year;
        std::string title;
    };

    void displayTimeline() {
        json data = FileManager::loadJSON("events.json");
        if (!data.is_array()) {
            std::cerr << "Error: events.json is not a valid array or could not be loaded.\n";
            return;
        }

        std::vector<TimelineEvent> timelineEvents;
        for (const auto& event : data) {
            int year = event.value("year", 0);
            std::string title = event.value("title", "<Unknown>");
            timelineEvents.push_back({ year, title });
        }

        std::sort(timelineEvents.begin(), timelineEvents.end(), [](const TimelineEvent& a, const TimelineEvent& b) {
            return a.year < b.year;
            });

        for (const auto& te : timelineEvents) {
            std::cout << std::setw(50) << "[" << te.year << "] ---- " << te.title << "\n";
        }

    }

}
