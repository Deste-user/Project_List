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





class Lista: public Subject {
public:
    explicit Lista(std::string nm):name_of_list(nm)  {}
    void subscribe(std::shared_ptr<Observer> A) override;
    void unsubscribe(std::shared_ptr<Observer> B) override;
    void notify() override;

    void add_to_list(std::shared_ptr<Product>& prod,int qty);
    void rem_to_list(std::shared_ptr<Product>& prod, int qty_to_remove);
    bool search_into_list(const std::shared_ptr<Product>& prod);
    void get_state() override;
    virtual ~Lista(){}



    //Getter&Setter

    const string &getNameOfList() const;

    void setNameOfList(const string &nameOfList);

    const list<std::shared_ptr<Product>> &getLst() const;

    void setLst(const list<std::shared_ptr<Product>> &lst);

    const list<std::shared_ptr<Observer>> &getObservers() const;

    void setObservers(const list<std::shared_ptr<Observer>> &observers);

private:
    std::string name_of_list;
    std::list<std::shared_ptr<Product>> lst;
    std::list<std::shared_ptr<Observer>> observers;
};


#endif //LISTA_LISTA_H
