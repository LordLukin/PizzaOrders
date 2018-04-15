#pragma once
#include <chrono>

using minutes = std::chrono::seconds;   // To simulate time flow ;)

class ITime
{
public:
    virtual void wait(minutes) = 0;
    virtual bool waitForBaking(minutes bakingTime, std::chrono::system_clock::time_point startTime) = 0;

    virtual ~ITime() {}
};
