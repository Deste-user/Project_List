//
// Created by Marco De Stefano on 07/07/21.
//

#ifndef LISTA_CPP_VIEWUTENTE_H
#define LISTA_CPP_VIEWUTENTE_H

#include "Observer.h"
#include <memory>
#include "Utente.h"

using namespace std;

class ViewUtente : public Observer {
public:
    ViewUtente() {}

    void observe(const std::shared_ptr<Utente> utente) {
        subject = utente;
        subject->subscribe(shared_from_this());
    }

    void update() override {
        subject->get_state();
    }

    ~ViewUtente() {
        subject->unsubscribe(shared_from_this());
    }

private:
    shared_ptr<Utente> subject;
};


#endif //LISTA_CPP_VIEWUTENTE_H
