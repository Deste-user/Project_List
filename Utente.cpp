//
// Created by Marco De Stefano on 08/04/21.
//

#include "Utente.h"


void Utente::add_list(std::string name_lst) {
    std::unique_ptr<Lista> lst(new Lista(name_lst));
    Elenco_Liste.push_back( move(lst));
    num_liste++;
}

bool Utente::search_list(std::string name) {
    for(auto & i : Elenco_Liste){
        if(i->getNameOfList()==name){
            return true;
        }
    }
    return false;
}


void Utente::remove_list(std::string name) {
    for (auto &iter : Elenco_Liste){
            if(iter->getNameOfList()==name){
                std::cout<<"vs"<<std::endl;
                Elenco_Liste.remove(*iter);
            }
        }
}