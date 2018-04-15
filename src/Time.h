#pragma once
#include "ITime.h"
#include "Pizzeria.h"

class Time: public ITime
{
public:
    void wait(minutes) override;
    bool waitForBaking(minutes bakingTime, std::chrono::system_clock::time_point startTime) override;

    virtual ~Time();
};
