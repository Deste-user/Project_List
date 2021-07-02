//
// Created by Marco De Stefano on 08/04/21.
//

#ifndef LISTA_CATEGORYPRODUCT_H
#define LISTA_CATEGORYPRODUCT_H
#include <string>
//Lazy Class or Data Class
class CategoryProduct {
public:
    explicit CategoryProduct(std::string nmCat):name(nmCat){}

    CategoryProduct(CategoryProduct& that):name(that.name){}

    CategoryProduct& operator=(CategoryProduct &that)
            {
        name=that.name;
        return *this;
    };

    const std::string &getName() const {
        return name;
    }


private:
     std::string name;
};


#endif //LISTA_CATEGORYPRODUCT_H
