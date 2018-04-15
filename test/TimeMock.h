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

    bool waitForBaking(minutes bakingTime, std::chrono::system_clock::time_point startTime) override
    {
        return false;
    }
};
