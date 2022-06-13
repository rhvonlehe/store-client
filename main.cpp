
#include <Store.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
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

}
