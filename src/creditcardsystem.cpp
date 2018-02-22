#include "creditcardsystem.h"
#include <iostream>

bool CreditCardSystem::charge(double price) const
 {
    std::string cardNumber;
    std::string owner;
    int monthValid;
    int yearValid;
    int ccv;
    std::cout << "Provide your credit card information:" << std::endl;
    std::cout << "Card number: ";
    std::cin >> cardNumber;
    std::cout << "Owner's name and surname: ";
    std::cin >> owner;
    std::cout << "Valid until month: ";
    std::cin >> monthValid;
    std::cout << "Valid until year: ";
    std::cin >> yearValid;
    std::cout << "CCV code: ";
    std::cin >> ccv;
    bool isDataValid = CreditCardSystem::enterData(cardNumber, owner, monthValid, yearValid, ccv);
    if (isDataValid)
    {
        return (price <= 100.0 ? true : false);
    }
    else
    {
        std::cout << "Invalid credit card data" << std::endl;
        return false;
    }
 }

