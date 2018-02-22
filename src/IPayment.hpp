#pragma once

class IPayment
{
public:
    virtual bool charge(double price) = 0;
};
