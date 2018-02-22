#pragma once
#include <list>
#include <set>
#include <chrono>
#include <string>

using minutes = std::chrono::seconds;   // To simulate time flow ;)

class Pizza
{
public:
    Pizza(std::string const & name, double price, minutes bakingTime);
    ~Pizza() = default;             // TODO: Non virtual destructor! Possible memory leaks
    virtual std::string getName();  // TODO: const correctnest
    virtual double getPrice() const;
    virtual minutes getBakingTime() const;

private:
    std::string name_;
    double price_;
    minutes bakingTime_;
};

using Pizzas = std::set<Pizza*>;
