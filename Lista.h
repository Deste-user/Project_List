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
    void attach(Observer *A) override;
    void dettach(Observer *B) override;
    void notify() override;

    void add_to_list(Product *prod,int qty);
    void rem_to_list(Product *prod, int qty_to_remove);
    bool search_into_list(Product *prod);
    void print_list();



    //Getter&Setter

    const string &getNameOfList() const;

    void setNameOfList(const string &nameOfList);

    int getNumOfElements() const;

    void setNumOfElements(int numOfElements);

    const list<Product *> &getLst() const;

    void setLst(const list<Product *> &lst);

    const list<Observer *> &getObservers() const;

    void setObservers(const list<Observer *> &observers);

private:
    std::string name_of_list;
    int num_of_elements=0;
    std::list<Product*> lst;
   std::list<Observer* > observers;
};


#endif //LISTA_LISTA_H
