#include "timelineDisplay.h"
#include "DAL.precompile.h"

using json = nlohmann::json;

namespace TimelineDisplay {

    struct TimelineEvent {
        int year;
        std::string title;
    };

    // Displays a timeline of events sorted by year in ascending order.
    void displayTimeline(EventManager& manager) {
        Event* current = manager.getHead();

        if (!current) {
            std::cout << "No events found.\n";
            return;
        }

        std::vector<TimelineEvent> timelineEvents;

        while (current) {
            timelineEvents.push_back({ current->year, current->title });
            current = current->next;
        }

        std::sort(timelineEvents.begin(), timelineEvents.end(), [](const TimelineEvent& a, const TimelineEvent& b) {
            return a.year < b.year;
            });

        for (const auto& te : timelineEvents) {
            std::cout << std::setw(50) << "[" << te.year << "] ---- " << te.title << "\n";
        }
    }

}