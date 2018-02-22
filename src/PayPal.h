#pragma once
#include <string>
#include <functional>

class PayPal
{
public:
    static int login(std::string username, std::string password)
    {
        std::hash<std::string> h;
        auto sessionId = h(username + password);
        return sessionId;
    }
    static bool pay(double price) { return true; }
};
