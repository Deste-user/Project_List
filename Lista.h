//
// Created by Marco De Stefano on 08/04/21.
//

#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H

#include <string>
#include <iostream>
#include <list>
#include "Product.h"
#include "Subject.h"
#include "Observer.h"

using namespace std;
class Lista {
public:
    explicit Lista(string nm) : name_of_list(nm) {}

    void add_to_list(shared_ptr<Product> &prod, int qty);

    void rem_to_list(shared_ptr<Product> &prod, int qty_to_remove);

    shared_ptr<Product> search_into_list(const shared_ptr<Product> &prod);

    void get_state();

    int num_product_in_list();

    int num_product_in_list_bought();

    //Getter&Setter
    const string &getNameOfList() const;

    void setNameOfList(const string &nameOfList);

    ~Lista() = default;

private:
    string name_of_list;
    list<shared_ptr<Product>> lst;
};


#endif //LISTA_LISTA_H
