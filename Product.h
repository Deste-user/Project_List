//
// Created by Marco De Stefano on 08/04/21.
//

#ifndef LISTA_PRODUCT_H
#define LISTA_PRODUCT_H

#include <string>
#include "CategoryProduct.h"
//Data Class
using namespace std;

class Product {
public:
    Product(const string nm, const CategoryProduct catg) : name(nm), category(catg) {}

    //Getter
    const CategoryProduct &getCategory() const;

    const string &getName() const;

    int getQuantity() const;

    void setQuantity(int quantity);

    bool isBought() const;

    void setBought(bool bought);

private:
    const string name;
    int quantity = 0;
    bool bought = false;
    //i cound use a string name to delete the useless class CategoryProduct
    const CategoryProduct category;
};


#endif //LISTA_PRODUCT_H
