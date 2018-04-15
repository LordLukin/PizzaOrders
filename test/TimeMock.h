#pragma once
#include<gmock/gmock.h>
#include "ITime.h"

class TimeMock: public ITime
{
public:
    void wait(minutes) override
    {

    }
    virtual ~TimeMock();
};
