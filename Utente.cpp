//
// Created by Marco De Stefano on 08/04/21.
//

#include "Utente.h"


void Utente::Create_list(string &name) {
    Lista* lst(new Lista(name));
    lst->attach(this);
    Elenco_Liste.push_back(lst);
    num_liste++;

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
    return 0;
}


/*
//Stampa
void Utente::Print_List()
{
    for(auto i:Elenco_Liste)
    {
    std::cout<< i->getNameOfList() <<std::endl;
   }
}



void Utente::Delete_list(const string &name) {

    for (auto iter=Elenco_Liste.begin();iter!= Elenco_Liste.end();iter++){
            if((*iter)->getNameOfList()==name)
            {
                (*iter)->dettach(this);
                Elenco_Liste.remove(*iter);
                //Elenco_Liste.erase(iter)
                //iter--;
            }
    }


}*/

void Utente::add_product_toList(Product *product ,string namelist,int qty) {


    Lista* result= search_name_list(namelist);

    if(result->getNameOfList()==namelist)
    {

        result->add_to_list(product , qty);
        subject=result;
    }
    this->Update();

}

void Utente::Update() {
    subject->print_list();
}

void Utente::remove_product_toList(Product *product, string namelist, int qty) {
    Lista* result= search_name_list(namelist);
    if(result->getNameOfList()==namelist){
        subject=result;
        result->rem_to_list(product,qty);

    }
    this->Update();

}

