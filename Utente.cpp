//
// Created by Marco De Stefano on 08/04/21.
//

#include "Utente.h"


void Utente::Create_list(string &name) {
    Lista* lst(new Lista(name));
    lst->subscribe(this);
    Elenco_Liste.push_back(lst);
    num_liste++;
}

void Utente::add_a_list(Lista &list){
    subject=&list;
    attach();
    Elenco_Liste.push_back(&list);
}



Lista* Utente::search_name_list(std::string &name)
{
    int count=0;
    for(auto i: Elenco_Liste)
    {
        count++;
        if(i->getNameOfList()==name)
        {
            return i;
        }
    }
    return nullptr;
}



//Stampa
void Utente::Print_List()
{

    std::cout<<this->getNameOfUtente()<<"->" <<"Raccolta Liste:"<<std::endl;
    for(auto i:Elenco_Liste)
    {
    std::cout<< i->getNameOfList() <<std::endl;

   }
    std::cout<<"---------------------------------"<<std::endl;
}



void Utente::Delete_list(const string &name) {

    for (auto iter=Elenco_Liste.begin();iter!= Elenco_Liste.end();iter++){
            if((*iter)->getNameOfList()==name)
            {
                (*iter)->unsubscribe(this);
                Elenco_Liste.remove(*iter);
                //Elenco_Liste.erase(iter)
                //iter--;
            }
    }


}

void Utente::add_product_toList(Product *product ,string namelist,int qty) {


    Lista* result= search_name_list(namelist);

    if(result->getNameOfList()==namelist)
    {
        subject = result;
        subject->add_to_list(product , qty);
    }


}

void Utente::Update(){
    std::cout<<this->getNameOfUtente()<<std::endl;
    subject->print_list();
}

void Utente::remove_product_toList(Product *product, string namelist, int qty) {
    Lista* result= search_name_list(namelist);

    if(result->getNameOfList()==namelist)
    {
        subject=result;
        subject->rem_to_list(product,qty);
    }
    this->Update();

}


void Utente::attach(){
    subject->subscribe(this);
}
void Utente::dettach() {
    subject->unsubscribe(this);
}




//Getter and Setter



const string &Utente::getNameOfUtente() const {
    return name_of_utente;
}

void Utente::setNameOfUtente(const string &nameOfUtente) {
    name_of_utente = nameOfUtente;
}













