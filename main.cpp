#include <iostream>
#include "Lista.h"
#include "Utente.h"
#include "CategoryProduct.h"
int main() {






    Utente* user(new Utente("Mario"));
    string nm="mamma";
    user->Create_list(nm);
    CategoryProduct Frutta("Frutta");
    Product* mela(new Product("Mela",Frutta));
    user->add_product_toList(mela,nm,4);
    user->add_product_toList(mela,nm,4);
    Product* pera(new Product("Pera",Frutta));
    user->add_product_toList(pera,nm,2);
    user->remove_product_toList(pera,nm,1);
    //user->remove_product_toList(pera,nm,7);
    Product* banana(new Product("Banana",Frutta));
    user->add_product_toList(banana,nm,1);
    user->remove_product_toList(banana,nm,1);





    return 0;
}
