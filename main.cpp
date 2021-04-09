#include <iostream>
#include "Lista.h"
#include "Utente.h"
int main() {
    Utente a("Mario:");
    std::cout<<"Inizio"<<std::endl;
    a.add_list("Spesa");
    a.add_list("Ikea");
    a.add_list("Spesa nonna");
    a.print_name_list();
    std::cout<<"Fine:"<<std::endl;
    a.remove_list("Ikea");

    a.print_name_list();

    return 0;
}
