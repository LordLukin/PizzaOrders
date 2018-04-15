#pragma once
#include "ITime.h"
#include "Pizzeria.h"



class Time: public ITime
{
public:
    void wait(minutes) override;
    bool waitForBaking(minutes bakingTime, StartTime startTime) override;
    bool waitForDelivery(StartTime startTime);
    virtual ~Time();
};
