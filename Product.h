//
// Created by Marco De Stefano on 08/04/21.
//

#ifndef LISTA_PRODUCT_H
#define LISTA_PRODUCT_H
#include <string>
#include "CategoryProduct.h"

class Product {
public:
    Product(std::string nm,int qt, CategoryProduct catg):name(nm),quantity(qt),category(catg){}

private:
 std::string name;
    int quantity;
    CategoryProduct category;
};


#endif //LISTA_PRODUCT_H
