//
// Created by Marco De Stefano on 08/04/21.
//

#include "Utente.h"


void Utente::create_list(const string name) {
    shared_ptr<Lista> lst(new Lista(name));
    elenco_liste.push_back(lst);
    notify();
}

void Utente::add_a_list(std::shared_ptr<Lista> list) {
    if (list != nullptr) {
        elenco_liste.push_back(list);
        notify();
    }
}


std::shared_ptr<Lista> Utente::search_name_list(std::string name) {
    for (auto i: elenco_liste) {
        if (i->getNameOfList() == name) {
            return i;
        }
    }
    return nullptr;
}

//Stampa
void Utente::print_all_list() {
    if (*elenco_liste.begin() != nullptr) {
        for (auto i : elenco_liste) {
            std::cout << i->getNameOfList() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    } else throw std::invalid_argument("Smart_pointer point to nullptr");
}


void Utente::delete_list(const string &name) {
    bool esito = false;

    for (auto iter = elenco_liste.begin(); iter != elenco_liste.end(); iter++) {
        if ((*iter)->getNameOfList() == name) {
            elenco_liste.erase(iter);
            esito = true;
        }
    }
    if (esito) {
        notify();
    } else throw std::invalid_argument("There is no list with this name");
}


void Utente::add_product_to_list(std::shared_ptr<Product> product, const string &namelist, const int qty) {
    bool esito = false;
    for (auto &i:elenco_liste) {
        if (i->getNameOfList() == namelist) {
            i->add_to_list(product, qty);
            esito = true;
        }
    }
    if (!esito) {
        throw std::invalid_argument("List absent ");
    }
}


void Utente::remove_product_to_list(std::shared_ptr<Product> product, string namelist, const int qty) {
    bool esito = false;
    for (auto &j:elenco_liste) {
        if (j->getNameOfList() == namelist) {
            j->rem_to_list(product, qty);
            esito = true;
        }
    }
    if (!esito) {
        throw std::invalid_argument("List absent ");
    }
}


void Utente::buy_a_product(std::shared_ptr<Product> product, string namelist) {
    auto result = search_name_list(namelist);

    if (result) {
        auto i = result->search_into_list(product);
        if (i) {
            i->setBought(true);
            result->get_state();
        } else
            throw std::invalid_argument("Product absent");
    } else
        throw std::invalid_argument("List absent");
}


int Utente::num_of_list() {
    int count=0;
    for(auto i:elenco_liste){
        count++;
    }
    return count;
}





//Getter and Setter



const string &Utente::getNameOfUtente() const {
    return name_of_utente;
}

void Utente::setNameOfUtente(const string &nameOfUtente) {
    name_of_utente = nameOfUtente;
}

//interfaccia Subject

void Utente::unsubscribe(shared_ptr<Observer> B) {
    obs_utente.remove(B);
}


void Utente::subscribe( shared_ptr<Observer> A) {
    obs_utente.push_back(A);
}

void Utente::notify() {
    for (auto &i:obs_utente) {
        i->update();
    }
}

void Utente::get_state() {
    cout << "Utente:" << this->getNameOfUtente() << endl;
    cout<<"Numero liste Disponibili:  "<<num_of_list()<<endl;
    cout << "Liste:" << endl;
    print_all_list();
}

void Utente::select_quantity_prod(string name_list,shared_ptr<Product> prod,int qty) {
    auto result= search_name_list(name_list);
    auto ptr= result->search_into_list(prod);
    ptr->setQuantity(qty);
    result->get_state();
}





















