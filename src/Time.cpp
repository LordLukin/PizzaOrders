#include "Time.h"
#include <thread>
#include "Pizzeria.h"

Time::~Time()
{}

void Time::wait(minutes)
{
     std::this_thread::sleep_for(minutes(2));
}

bool Time::waitForBaking(minutes bakingTime, std::chrono::system_clock::time_point startTime)
{
    auto now = std::chrono::system_clock::now();
    return bakingTime < (now - startTime);
}

