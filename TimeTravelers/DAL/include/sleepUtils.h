#pragma once

#include <chrono>
#include <thread>

inline void sleepMs(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}