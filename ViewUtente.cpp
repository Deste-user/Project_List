//
// Created by Marco De Stefano on 07/07/21.
//

#include "ViewUtente.h"

void ViewUtente::attach() {
subject->subscribe(std::shared_ptr<ViewUtente>(this));
}

void ViewUtente::detach() {

  subject->unsubscribe(std::shared_ptr<ViewUtente>(this));
}

void ViewUtente::update(shared_ptr<Subject> sub){
    sub->get_state();
    cout<<"eueuue"<<endl;
}


