//
// Created by Marco De Stefano on 08/04/21.
//

#ifndef LISTA_CATEGORYPRODUCT_H
#define LISTA_CATEGORYPRODUCT_H
#include <string>

class CategoryProduct {
public:
    explicit CategoryProduct(std::string nmCat):name(nmCat){}

    const std::string &getName() const {
        return name;
    }

private:
    const std::string name;
};


#endif //LISTA_CATEGORYPRODUCT_H
