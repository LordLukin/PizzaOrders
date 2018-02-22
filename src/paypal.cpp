#include "paypal.h"
#include <iostream>

bool PayPal::charge(double price) const
{
        std::string username;
        std::string password;
        std::cout << "Provide your PayPal credentials" << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
        if (login(username, password) == 0)
        {
            return false;
        }
        return pay(price);
}
