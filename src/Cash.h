#pragma once
#include <IPayment.hpp>
#include <iostream>

class Cash : public IPayment
{
public:
    bool charge(double price)
    {
        std::cout << "Payment by cash selected. Please prepare " << price << " SEK in cash. " << std::endl;
        return true;
    }

};
