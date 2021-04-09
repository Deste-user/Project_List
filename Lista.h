//
// Created by Marco De Stefano on 08/04/21.
//

#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H
#include <string>
#include <memory>
#include <vector>
#include "Product.h"

class Lista {
public:
    explicit Lista(std::string nm):name_of_list(nm){}

    int getNumOfElements() const {
        return num_of_elements;
    }

    void setNumOfElements(int numOfElements) {
        num_of_elements = numOfElements;
    }

    const std::string &getNameOfList() const {
        return name_of_list;
    }

    void setNameOfList(const std::string &nameOfList) {
        name_of_list = nameOfList;
    }
    //implemento Observer
private:
    std::string name_of_list;
    int num_of_elements=0;
    std::vector<std::unique_ptr<Product>> lst;
};


#endif //LISTA_LISTA_H
