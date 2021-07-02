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
#include "Observer.h"
using namespace std;

class  Utente: public Observer{
public:
    explicit Utente(string nm):name_of_utente(nm){}
    void Create_list( string &name);
    Lista* search_name_list(string &name);
    void Delete_list(const string &name);
    void Print_List();
    void Update() override;
    void add_product_toList(Product *product,string namelist,int qty);
    void remove_product_toList(Product *product,string namelist,int qty);


private:
    std::string name_of_utente;
    std::list<Lista*> Elenco_Liste;
    int num_liste=0;
    Lista *subject;
};


#endif //LISTA_UTENTE_H
