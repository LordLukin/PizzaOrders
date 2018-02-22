#include "dotpay.h"
#include <iostream>

 bool DotPay:: charge(double price) const
 {
     std::cout << "DotPay payment was chosen" << std::endl;
     int timer = 0;
     bool valid;
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
