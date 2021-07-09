//
// Created by Marco De Stefano on 08/04/21.
//

#include "Lista.h"
#include <memory>

void Lista::add_to_list(std::shared_ptr<Product>& prod,int qty)
{
    if(qty>0){
      if (search_into_list(prod))
      {
        for (auto i = lst.begin(); i != lst.end(); i++){
            if ((*i)->getName() == prod->getName())
            {
                (*i)->setQuantity(qty + (*i)->getQuantity());
            }
        }
      }else {
        prod->setQuantity(qty);
        lst.push_back(prod);
      }
      this->notify();
    }else if (qty==0)
        throw std::invalid_argument("Not enough quantity of Products ");
    else
        throw std::invalid_argument("Can't add a negative number of Products");
}




void Lista::rem_to_list(std::shared_ptr<Product >& prod, int qty_to_remove)
{
    if(qty_to_remove>0){
    if(search_into_list(prod))
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
        this->notify();
    }
}else if(qty_to_remove==0){
        throw std::invalid_argument("Can't remove zero product");
    }else throw std::invalid_argument("Can't add product");
}




bool Lista::search_into_list(const std::shared_ptr<Product>& prod) {
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





void Lista::get_state()
{
    std::cout<<this->getNameOfList()<<":"<<std::endl;

    for (auto i=lst.begin();i!=lst.end();i++)
    {
        std::cout<<(*i)->getName()<<"->"<< (*i)->getQuantity()<<std::endl;
    }
    std::cout<<"-----------------------------------"<<std::endl;
}

void Lista::subscribe( std::shared_ptr<Observer> A) {
observers.push_back(A);
}

void Lista::unsubscribe(std::shared_ptr<Observer> B)  {
observers.remove(B);
}

void Lista::notify(){
    for (const auto &i: observers) {
        i->update(shared_ptr<Lista> (this));
    }
}


//Getter and Setter



const list<std::shared_ptr<Product>> &Lista::getLst() const {
    return lst;
}

void Lista::setLst(const list<std::shared_ptr<Product>> &lst) {
    Lista::lst = lst;
}

const list<std::shared_ptr<Observer>> &Lista::getObservers() const {
    return observers;
}

void Lista::setObservers(const list<std::shared_ptr<Observer>> &observers) {
    Lista::observers = observers;
}








