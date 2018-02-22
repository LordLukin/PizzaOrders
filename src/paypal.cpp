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
        login(username, password);   // TODO: Return value checking! Was login successful?
        return pay(price);
}
