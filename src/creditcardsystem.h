#pragma once
#include <string>
#include "paymentstrategy.h"

class CreditCardSystem : public PaymentStrategy
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


   virtual bool charge(double price) const override;
};
