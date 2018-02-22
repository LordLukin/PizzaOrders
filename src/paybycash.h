#ifndef PAYBYCASH_H
#define PAYBYCASH_H
#include "paymentstrategy.h"


class PayByCash : public PaymentStrategy
{
public:
    bool charge(double price) const override;
};


#endif // PAYBYCASH_H
