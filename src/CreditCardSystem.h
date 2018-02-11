#pragma once
#include <string>

class CreditCardSystem
{
public:
    bool enterData(std::string cardNumber, std::string owner, int monthValid, int yearValid, int ccv)
    {
        // REFACTOR: to return ccv != 0;
        if (ccv == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool charge(double price)
    {
        if (price <= 15.0)
        {
            return true;
        }
        else
        {
            // unexpected false, not enough amount of cash on the card
            return false;
        }
    }
};