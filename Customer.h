#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Store.h"
#include <cstdint>


class Customer
{
public:
    Customer() = default;

    // itemsToPurchase is the number of attempted purchases
    void run(uint32_t itemsToPurchase);
private:
    Store store;
};

#endif // CUSTOMER_H
