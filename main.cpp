#include <iostream>
#include "Lista.h"
#include "Utente.h"
#include "Product.h"
#include "ViewUtente.h"

#include "CategoryProduct.h"
int main() {
    std::shared_ptr<Utente> utente1(new Utente("Mario"));
    std::shared_ptr<Utente> utente2(new Utente("Giorgio"));
    std::shared_ptr<Lista> lista(new Lista("spesa"));
    std::shared_ptr<Lista> lista1(new Lista("Nonna"));

    ViewUtente GUI(utente1);
    ViewUtente GUI1(utente2);

    utente2->add_a_list(lista1);
    utente1->add_a_list(lista1);
    utente1->add_a_list(lista);





    CategoryProduct Frutta("Frutta");
    shared_ptr<Product> product(new Product("Mela", Frutta));

    utente2->add_a_list(utente1->search_name_list("spesa"));

    utente1->add_product_to_list(product,"spesa",4);
    utente1->add_product_to_list(product,"spesa",5);


    utente1->buy_a_product(product,"spesa");
    utente1->remove_product_to_list(product,"spesa",2);
    utente1->delete_list("Nonna");


    return 0;
}
