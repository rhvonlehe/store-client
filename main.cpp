
#include "Customer.h"
#include <Store.h>
#include <iostream>
#include <assert.h>
#include <vector>
#include <thread>


using namespace std;


void threadEntry(int numPurchases)
{
//    srand(static_cast<unsigned int>(time(nullptr)));
    Customer customer;
    customer.run(numPurchases);
}

int main(int argc, char* argv[])
{
    assert(argc == 3);
    int numCustomers = atoi(argv[1]);
    int numPurchases = atoi(argv[2]);

    vector<thread> threads;

    for (int i=0; i < numCustomers; i++)
    {
        threads.push_back(thread(threadEntry, numPurchases));
    }

    for (auto& th : threads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }


#if 0 // todo remove
    Store store;

    auto families = store.getProductFamilies();

    cout << "Product families: " << endl;

    for (const auto& family : families)
    {
        cout << family <<endl;
    }

    auto products = store.getProductsInFamily(families[0]);

    for (auto& product : products)
    {
        product.print();
    }

    auto toBuy = products[0];
    cout << "Try to buy the below:" << endl;
    toBuy.print();

    store.purchaseProduct(products[0].id);

    auto bought = store.getProductInfo(toBuy.id);
    cout << "After purchase: " << endl;
    bought.print();
#endif
}
