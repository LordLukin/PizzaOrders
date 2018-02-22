#pragma once
#include <string>
#include <functional>
#include "IPayment.hpp"
#include <iostream>

class PayPal : public IPayment
{
public:
    bool charge(double price)
    {
        std::string username;
        std::string password;
        std::cout << "Provide your PayPal credentials" << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
        login(username, password);   // TODO: Return value checking! Was login successful?
        return pay(price);
    }

private:
    int login(std::string username, std::string password)
    {
        std::hash<std::string> h;
        auto sessionId = h(username + password);
        return sessionId;
    }
    bool pay(double price) { return true; }
};
