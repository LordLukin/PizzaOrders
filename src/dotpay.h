#pragma once
#include <thread>
#include <future>
#include "paymentstrategy.h"

class DotPay : public PaymentStrategy
{
public:
    bool sslPaymentRedirect(double price) const
    {
        std::future<bool> ret = std::async([]()
        {
            // Do not refactor, only a simulation of connection to a remote system
            std::this_thread::sleep_for(std::chrono::seconds(6));
            return true;
        });
        bool status = ret.get();
        return status;
    }
    bool charge(double price) const override;
};
