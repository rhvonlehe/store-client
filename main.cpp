
#include <Store.h>
#include <iostream>

using namespace std;

int main(void)
{
    Store store;

    auto families = store.getProductFamilies();

    cout << "Product families: " << endl;

    for (const auto& family : families)
    {
        cout << family <<endl;
    }
}
