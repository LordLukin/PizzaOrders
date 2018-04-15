#pragma once
#include <chrono>

using minutes = std::chrono::seconds;   // To simulate time flow ;)
using StartTime = std::chrono::system_clock::time_point;

class ITime
{
public:
    virtual void wait(minutes) = 0;
    virtual bool waitForBaking(minutes bakingTime, StartTime startTime) = 0;
    virtual bool waitForDelivery(StartTime startTime) = 0;
    virtual ~ITime() {}
};
