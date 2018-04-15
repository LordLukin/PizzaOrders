#pragma once
#include "ITime.h"

class Time: public ITime
{
public:
    void wait(minutes) override;
    virtual ~Time();
};
