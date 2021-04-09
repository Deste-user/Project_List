//
// Created by Marco De Stefano on 08/04/21.
//

#ifndef LISTA_UTENTE_H
#define LISTA_UTENTE_H
#include <string>
#include <list>
#include<memory>
#include "Lista.h"
#include "iostream"
using namespace std;

class Utente {
public:
    explicit Utente(std::string nm):name_of_utente(nm){}
    void add_list(std::string name_lst);
    bool search_list(std::string name);
    void remove_list(std::string name);
    void print_name_list(){
        for(auto &iter: Elenco_Liste){

            std::cout<<iter->getNameOfList()<<std::endl;
        }
    };

private:
    std::string name_of_utente;
    std::list<std::unique_ptr<Lista>> Elenco_Liste;
    int num_liste=0;
};


#endif //LISTA_UTENTE_H
