#pragma once

class PaymentStrategy
{
public:
    virtual ~PaymentStrategy() = default;
    virtual bool charge(double price) const = 0;
};

