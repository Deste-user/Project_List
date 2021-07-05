//
// Created by Marco De Stefano on 08/04/21.
//

#ifndef LISTA_PRODUCT_H
#define LISTA_PRODUCT_H
#include <string>
#include "CategoryProduct.h"
//Data Class
using namespace std;

class Product{
public:
    Product(string nm, CategoryProduct catg):name(nm),category(catg){}



    //Getter&Setter

    const CategoryProduct &getCategory() const;

    void setCategory( CategoryProduct &category);

    const string &getName() const;

    void setName(const string &name);

    int getQuantity() const;

    void setQuantity(int quantity);

private:
    string name;
    int quantity=0;
    //i cound use a string name to delete the useless class CategoryProduct
    CategoryProduct category;
};


#endif //LISTA_PRODUCT_H
