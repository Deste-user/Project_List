//
// Created by Marco De Stefano on 08/04/21.
//

#include "Product.h"




int Product::getQuantity() const {
    return quantity;
}

const string &Product::getName() const {
    return name;
}

const CategoryProduct &Product::getCategory() const {
    return category;
}

void Product::setQuantity(int quantity) {
    Product::quantity = quantity;
}

bool Product::isBought() const {
    return bought;
}

void Product::setBought(bool bought) {
    Product::bought = bought;
}





