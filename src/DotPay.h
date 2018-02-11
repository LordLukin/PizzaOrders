#pragma once
#include <thread>
#include <future>

class DotPay
{
public:
    bool sslPaymentReditect(double price)
    {
        std::future<bool> ret = std::async([]()
        {
            std::this_thread::sleep_for(std::chrono::seconds(7));
            return true;
        });
        bool status = ret.get();
        return status;
    }
};