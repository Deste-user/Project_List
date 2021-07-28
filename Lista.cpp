//
// Created by Marco De Stefano on 08/04/21.
//

#include "Lista.h"
#include <memory>

void Lista::add_to_list(std::shared_ptr<Product> &prod, int qty) {
    if (qty >= 0) {

        if (search_into_list(prod)) {
            for (auto i :lst) {
                if (i->getName() == prod->getName()) {
                    i->setQuantity(qty + i->getQuantity());
                }
            }
        } else {
            prod->setQuantity(qty);
            lst.push_back(prod);
        }
        get_state();

    } else
        throw std::invalid_argument("Can't add a negative number of Products");
}

void Lista::rem_to_list(std::shared_ptr<Product> &prod, int qty_to_remove) {
    if (qty_to_remove > 0) {

        if (search_into_list(prod)) {

            for (auto i = lst.begin(); i != lst.end(); i++) {
                if ((*i)->getName() == prod->getName()) {
                    if ((*i)->getQuantity() <= qty_to_remove) {
                        lst.erase(i);
                    } else {
                        (*i)->setQuantity((*i)->getQuantity() - qty_to_remove);
                    }
                }
            }
            this->get_state();
        } else throw invalid_argument("Product not avable");
    } else if (qty_to_remove == 0) {
        throw invalid_argument("Can't remove zero product");
    } else throw invalid_argument("Can't add product");
}

shared_ptr<Product> Lista::search_into_list(const std::shared_ptr<Product> &prod) {
    for (auto i:lst) {
        if (i->getName() == prod->getName()) {
            return i;
        }
    }
    return nullptr;
}

void Lista::get_state() {
    std::cout << "Lista:  " << this->getNameOfList() << std::endl;
    cout << "Bought:" << num_product_in_list_bought() << "/" << num_product_in_list() << endl;

    for (auto &i:lst) {

        if (i->getQuantity() != 0) {
            if (!(i->isBought())) {
                std::cout << i->getName() << "->" << i->getQuantity() << "--->" << "Not Bought" << std::endl;
            } else
                std::cout << i->getName() << "->" << i->getQuantity() << "--->" << "Bought" << std::endl;
        } else
            std::cout << i->getName() << "->" << "undetermined" << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}

int Lista::num_product_in_list() {
    return lst.size();
}

int Lista::num_product_in_list_bought() {
    int count = 0;
    for (auto i: lst) {
        if (i->isBought()) {
            count++;
        }
    }
    return count;
}
//Getter and Setter

const string &Lista::getNameOfList() const {
    return name_of_list;
}

void Lista::setNameOfList(const string &nameOfList) {
    name_of_list = nameOfList;
}







