#pragma once
#include <vector>
#include <chrono>
#include <string>

using minutes = std::chrono::seconds;   // To simulate time flow ;)

class Pizza
{
public:
    Pizza(std::string const & name, double price, minutes bakingTime);

    Pizza(const Pizza &) = default;
    Pizza & operator=(const Pizza &) = default;
    Pizza(Pizza &&) noexcept = default;
    Pizza & operator=(Pizza &&) noexcept = default;
    Pizza() = delete;
    ~Pizza() = default;

    std::string getName() const;  // TODO: const correctnest
    double getPrice() const;
    minutes getBakingTime() const;

private:
    std::string name_;
    double price_;
    minutes bakingTime_;
};

using Pizzas = std::vector<Pizza>;
