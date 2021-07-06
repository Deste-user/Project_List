//
// Created by Marco De Stefano on 08/04/21.
//

#include "Lista.h"

void Lista::add_to_list(Product *prod,int qty) {
    if(qty>0){
    if (search_into_list(prod))
    {
        for (auto i = lst.begin(); i != lst.end(); i++){
            if ((*i)->getName() == prod->getName())
            {
                (*i)->setQuantity(qty + (*i)->getQuantity());
            }
        }
    }
    else {
        prod->setQuantity(qty);
        lst.push_back(prod);
    }
    }else if (qty==0)
        throw std::invalid_argument("Not enough quantity of Products ");
    else
        throw std::invalid_argument("Can't add a negative number of Products");
}




void Lista::rem_to_list(Product *prod, int qty_to_remove)
{
    if(qty_to_remove>0){
    if(search_into_list(prod)) //controllo per vedere se c'è nella lista
    {
        for(auto i=lst.begin();i!=lst.end(); i++){
            if ((*i)->getName() == prod->getName())
            {
              if((*i)->getQuantity()<=qty_to_remove)
              {
                lst.erase(i);
              }else{
                (*i)->setQuantity((*i)->getQuantity()-qty_to_remove);
              }
           }
        }
    }
}else if(qty_to_remove==0){
        throw std::invalid_argument("Can't remove zero product");
    }else throw std::invalid_argument("Can't add product");
}


bool Lista::search_into_list(Product *prod) {
    if(prod!=nullptr) {
        for (auto i = lst.begin(); i != lst.end(); i++) {
            if ((*i)->getName() == prod->getName()) {
                return true;
            }
        }
       return false;
    } throw std::invalid_argument("Illegal address");
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

        std::cout<<i->getName()<<"->"<< i->getQuantity()<<std::endl;
    }
}

void Lista::subscribe(Observer *A) {
observers.push_back(A);
}

void Lista::unsubscribe(Observer *B)  {
observers.remove(B);
}

void Lista::notify(){
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


