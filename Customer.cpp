#include "Customer.h"
#include <thread>
#include <chrono>

using namespace std;

const uint32_t randomDelayMaxMs = 500;


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

        int randomFamily = rand() % families.size();

        auto familyProducts = store.getProductsInFamily(families[randomFamily]);

        int randomProductIndex = rand() % familyProducts.size();

        auto product = store.getProductInfo(familyProducts[randomProductIndex].id);

        auto result = store.purchaseProduct(product.id); // discard result
        itemsToPurchase--;                               // decrement whether attempt worked or not

        uint32_t sleepTime = rand() % randomDelayMaxMs;
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
    }

}
