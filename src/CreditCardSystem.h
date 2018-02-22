#pragma once
#include <string>

class CreditCardSystem
{
public:
   static bool enterData(std::string cardNumber, std::string owner, int monthValid, int yearValid, int ccv)
    {
        // TODO: to return ccv != 0;
        // Stupid simulation of checking if credit card data is valid
        if (ccv == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }


   static bool charge(double price)
    {
        if (price <= 100.0)
        {
            return true;
        }
        else
        {
            // Simulation for not enough amount of money on the card
            return false;
        }
    }
};
