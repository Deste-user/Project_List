#include <iostream>
#include "Lista.h"
#include "Utente.h"
#include "ViewUtente.h"

#include "CategoryProduct.h"
int main() {
    std::shared_ptr<Utente> utente1(new Utente("Mario"));
    std::shared_ptr<Utente> utente2(new Utente("Giorgio"));

    ViewUtente GUI(utente1);
    ViewUtente GUI1(utente2);

    std::shared_ptr<Lista> lista(new Lista("spesa"));
    utente1->add_a_list(lista);

    std::cout<<"ncòn"<<std::endl;
    //utente2->add_a_list((std::shared_ptr<Lista>(utente1->search_name_list("Spesa"))));


    return 0;
}
