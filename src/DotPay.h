#pragma once
#include <thread>
#include <future>

class DotPay
{
public:
    static bool sslPaymentReditect(double price)
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
};
