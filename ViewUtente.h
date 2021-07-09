//
// Created by Marco De Stefano on 07/07/21.
//

#ifndef LISTA_CPP_VIEWUTENTE_H
#define LISTA_CPP_VIEWUTENTE_H
#include "Observer.h"
#include <memory>
#include "Utente.h"

using namespace std;
class ViewUtente: public Observer {
public:
    ViewUtente(  shared_ptr<Utente> utente): subject(move(utente))
    {
        attach();
    }

    void attach() override;
    void detach() override;
    void update(shared_ptr<Subject> sub) override;

    ~ViewUtente() override
    {
        detach();
    }

private:
    shared_ptr<Utente> subject;
};


#endif //LISTA_CPP_VIEWUTENTE_H
