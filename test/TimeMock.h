#pragma once
#include <gmock/gmock.h>
#include "ITime.h"

class TimeMock: public ITime
{
public:
    void wait(minutes) override
    {

    }
    virtual ~TimeMock() {}

    bool waitForBaking(minutes bakingTime, StartTime startTime) override
    {
        return false;
    }

    bool waitForDelivery(StartTime startTime)
    {
        return true;
    }
};
