#include <iostream>
#include "Lista.h"
#include "Utente.h"
#include "CategoryProduct.h"
int main() {

    Utente* user(new Utente("Mario"));
    Utente* user3(new Utente("Lorenzo"));
    string nm="Per Nonna";
    user->Create_list(nm);
    Lista* list1(new Lista(nm));
    Lista* list(new Lista("Spesa"));
    user3->add_a_list(*list);
    user3->add_a_list(*list1);

    user3->Print_List();
    user->add_a_list(*list);
    user->Print_List();

    CategoryProduct Frutta("Frutta");

    Product* mela(new Product("Mela",Frutta));

    user3->add_product_toList(mela,list->getNameOfList(),4);
    user->add_product_toList(mela,list->getNameOfList(),4);

    Product* pera(new Product("Pera",Frutta));

    user->add_product_toList(pera,nm,2);
    user->remove_product_toList(pera,nm,1);
    user->remove_product_toList(pera,nm,7);

    Product* banana(new Product("Banana",Frutta));

    user->add_product_toList(banana,nm,1);
    user->remove_product_toList(mela,nm,9);





    return 0;
}
