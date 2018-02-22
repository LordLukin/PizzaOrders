#pragma once
#include <string>

class CreditCardSystem
{
public:
    bool charge(double price)
    {
        bool success = false;
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
        bool isDataValid = enterData(cardNumber, owner, monthValid, yearValid, ccv);
        if (isDataValid)
        {
            success = chargeCC(price);
        }
        else
        {
            std::cout << "Invalid credit card data" << std::endl;
        }
        return success;
    }

private:
    bool enterData(std::string cardNumber, std::string owner, int monthValid, int yearValid, int ccv)
    {
        // TODO: to return ccv != 0;
        // Stupid simulation of checking if credit card data is valid
        if (ccv == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool chargeCC(double price)
    {
        if (price <= 100.0)
        {
            return true;
        }
        else
        {
            // Simulation for not enough amount of money on the card
            return false;
        }
    }
};
