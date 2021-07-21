#include <iostream>
#include "Lista.h"
#include "Utente.h"
#include "Product.h"
#include "ViewUtente.h"
#include "CategoryProduct.h"


int main() {
    auto utente1= make_shared<Utente>("Mario");
    auto utente2= make_shared<Utente>("Giorgio");

    shared_ptr<ViewUtente> GUI1= make_shared<ViewUtente>();
    shared_ptr<ViewUtente> GUI2= make_shared<ViewUtente>();

    GUI1->observe(utente1);
    GUI2->observe(utente2);

    std::shared_ptr<Lista> lista(new Lista("spesa"));
    std::shared_ptr<Lista> lista1(new Lista("Nonna"));



    utente2->add_a_list(lista1);
    utente1->add_a_list(lista1);
    utente1->add_a_list(lista);
    utente2->add_a_list(utente1->search_name_list("spesa"));
    utente1->delete_list("Nonna");

    CategoryProduct Frutta("Frutta");
    shared_ptr<Product> product(new Product("Mela", Frutta));
    shared_ptr<Product> product1(new Product("Pera", Frutta));
    shared_ptr<Product> product2(new Product("Banana", Frutta));
    shared_ptr<Product> product3(new Product("Kiwi", Frutta));




    utente1->add_product_to_list(product,"spesa",0);
    utente1->select_quantity_prod("spesa",product,3);
    utente1->add_product_to_list(product,"spesa",5);
    utente1->add_product_to_list(product1,"spesa",2);
    utente2->add_product_to_list(product2,"Nonna",5);
    utente2->add_product_to_list(product3,"Nonna",3);

    utente1->buy_a_product(product,"spesa");
    utente2->buy_a_product(product2,"Nonna");
    utente2->buy_a_product(product3,"Nonna");
    utente1->remove_product_to_list(product,"spesa",2);



    return 0;
}
