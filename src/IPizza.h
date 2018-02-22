#pragma once
#include <string>
#include <chrono>

using minutes = std::chrono::seconds;

class IPizza
{
public:
    virtual std::string toString() const = 0;
    virtual double getPrice() const = 0;
    virtual minutes getBakingTime() const = 0;
};
