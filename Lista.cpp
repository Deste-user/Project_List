//
// Created by Marco De Stefano on 08/04/21.
//

#include "Lista.h"

void Lista::add_to_list(Product *prod,int qty) {
    if (search_into_list(prod))
    {
        for (auto i = lst.begin(); i != lst.end(); i++)
        {
            if ((*i)->getName() == prod->getName())
            {
                (*i)->setQuantity(qty + (*i)->getQuantity());
            }
        }
    }
    else{
           prod->setQuantity(qty);
           lst.push_back(prod);
          }
}

void Lista::rem_to_list(Product *prod, int qty_to_remove){
    if(search_into_list(prod)) //controllo per vedere se c'è nella lista
    {
        for(auto i=lst.begin();i!=lst.end(); i++){
            if((*i)->getQuantity()<=qty_to_remove)
            {
                i++;
                lst.erase(i);

            }else{
                (*i)->setQuantity((*i)->getQuantity()-qty_to_remove);
            }
        }
    }
}


bool Lista::search_into_list(Product *prod) {
    for(auto i=lst.begin();i!=lst.end();i++)
    {
        if((*i)->getName()==prod->getName())
        {
            return true;
        }
    }//std::cout<<"Nessuna prodotto con questo nome"<<std::endl;
    return false;
}



const string &Lista::getNameOfList() const {
    return name_of_list;
}

void Lista::setNameOfList(const string &nameOfList) {
    name_of_list = nameOfList;
}

int Lista::getNumOfElements() const {
    return num_of_elements;
}

void Lista::setNumOfElements(int numOfElements) {
    num_of_elements = numOfElements;
}



void Lista::print_list()
{
    std::cout<<"Lista:"<<std::endl;


    for (auto i:lst)
    {

        std::cout<<i->getName()<<"        "<< i->getQuantity()<<std::endl;
    }
}

void Lista::attach(Observer *A) {
observers.push_back(A);
}

void Lista::dettach(Observer *B) {
observers.remove(B);
}

void Lista::notify() {
for (auto i: observers)
{
    i->Update();
}

}

const list<Product *> &Lista::getLst() const {
    return lst;
}

void Lista::setLst(const list<Product *> &lst) {
    Lista::lst = lst;
}

const list<Observer *> &Lista::getObservers() const {
    return observers;
}

void Lista::setObservers(const list<Observer *> &observers) {
    Lista::observers = observers;
}


