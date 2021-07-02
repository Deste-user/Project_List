//
// Created by Marco De Stefano on 08/04/21.
//

#include "Product.h"




int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int quantity) {
    Product::quantity = quantity;
}

const string &Product::getName() const {
    return name;
}

void Product::setName(const string &name) {
    Product::name = name;
}

const CategoryProduct &Product::getCategory() const {
    return category;
}

void Product::setCategory( CategoryProduct &category) {
   Product::category.operator=(category);
}

/*void Product::setCategory(const CategoryProduct &category) {
    Product::category = category;
}*/

