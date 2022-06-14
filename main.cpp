
#include "Customer.h"
#include <Store.h>
#include <iostream>
#include <assert.h>
#include <vector>
#include <thread>


using namespace std;


void threadEntry(int numPurchases)
{
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
}
