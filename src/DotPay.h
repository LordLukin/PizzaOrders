#pragma once
#include <thread>
#include <future>
#include <IPayment.hpp>
#include <iostream>

class DotPay : public IPayment
{
public:
    bool charge(double price)
    {
        std::cout << "DotPay payment was chosen" << std::endl;
        int timer = 0;
        bool valid = false;
        std::cout << "Waiting for confirmation from online system" << std::endl;
        do  // TODO: observer pattern
        {
            std::chrono::seconds waitTime(1);
            std::this_thread::sleep_for(waitTime);
            timer += 1;
            valid = sslPaymentRedirect(price);
        } while (!valid && timer < 300);
        return valid;
    }

private:
    bool sslPaymentRedirect(double price)
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
