#pragma once
#include <string>

class Ingredient
{
public:
    Ingredient() = default;
private:
    std::string name_;
    double bakeTime_;
};
