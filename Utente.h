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

class  Utente: public Subject{
public:
    explicit Utente(string nm):name_of_utente(nm){}

    void create_list( const string name);
    void add_a_list(shared_ptr<Lista> list);
    shared_ptr<Lista> search_name_list(string name);
    void delete_list(const string &name);
    void print_all_list();

    void get_state() override;
    void subscribe(shared_ptr<Observer> A) override;
    void unsubscribe(shared_ptr<Observer> B) override;
    void notify() override;

    void add_product_to_list(shared_ptr<Product> product, const string& namelist,int qty);
    void remove_product_to_list(shared_ptr<Product> product,string namelist,int qty);
    void buy_a_product(shared_ptr<Product> product,string namelist);


    const string &getNameOfUtente() const;
    void setNameOfUtente(const string &nameOfUtente);

    const list<shared_ptr<Lista>> &getElencoListe() const;

    void setElencoListe(const list<shared_ptr<Lista>> &elencoListe);

    virtual ~Utente(){}

private:
    string name_of_utente;
    list<shared_ptr<Lista>> elenco_liste;
    //lista di observer
    list<shared_ptr<Observer>> obs_utente;
};


#endif //LISTA_UTENTE_H
