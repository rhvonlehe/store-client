#include "Customer.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <random>

using namespace std;
using namespace sl;

const uint32_t randomDelayMaxMs = 500;

int getRandomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);

    int retval = dist(mt);
    cout << "dist: " << retval << endl;
    return retval;
}


void Customer::run(uint32_t itemsToPurchase)
{
    // Loop doing same sequence:
    // 1. Get families
    // 2. Pick random family
    // 3. Pick random product in family
    // 4. Get Product info for product id
    // 5. Attempt purchase of that product id
    while (itemsToPurchase > 0)
    {
        auto families = store.getProductFamilies();

        int randomFamily = getRandomInt(0, static_cast<int>(families.size()));
        cout << "randomFamily: " << randomFamily;

        auto familyProducts = store.getProductsInFamily(families[randomFamily]);

        int randomProductIndex = getRandomInt(0, static_cast<int>(familyProducts.size()));

        auto product = store.getProductInfo(familyProducts[randomProductIndex].id);

        auto result = store.purchaseProduct(product.id);

        cout << "customer " << this_thread::get_id() << " bought product " << product.id;
        if (result == Store::RESULT_SUCCESS)
            cout << " successfully" << endl;
        else
            cout << " unsuccessfully" << endl;

        itemsToPurchase--;                               // decrement whether attempt worked or not

        uint32_t sleepTime = getRandomInt(1, 500);   //  rand() % randomDelayMaxMs;
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
    }

}

