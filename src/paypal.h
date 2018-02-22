#pragma once
#include <string>
#include <functional>
#include "paymentstrategy.h"

class PayPal : public PaymentStrategy
{
public:
   int login(std::string username, std::string password) const
    {
        std::hash<std::string> h;
        auto sessionId = h(username + password);
        return sessionId;
    }
    bool pay(double price) const { return true; }
    bool charge(double price) const override;
};

