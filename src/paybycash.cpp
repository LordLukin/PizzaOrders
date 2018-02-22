#include "paybycash.h"
#include <iostream>

PayByCash::PayByCash()
{

}

bool PayByCash::charge(double price) const
{

    std::cout << "Payment by cash selected. Please prepare " << price << " SEK in cash. " << std::endl;
    return true;



}

