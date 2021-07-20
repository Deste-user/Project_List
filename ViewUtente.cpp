//
// Created by Marco De Stefano on 07/07/21.
//

#include "ViewUtente.h"

void ViewUtente::attach() {
subject->subscribe(shared_ptr<ViewUtente>(this));
}

void ViewUtente::detach() {

  subject->unsubscribe(shared_ptr<ViewUtente>(this));
}

void ViewUtente::update()
{
    subject->get_state();
}


