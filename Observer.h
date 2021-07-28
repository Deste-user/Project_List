//
// Created by Marco De Stefano on 15/04/21.
//

#ifndef LISTA_OBSERVER_H
#define LISTA_OBSERVER_H

#include <memory>

class Subject;

class Observer : public enable_shared_from_this<Observer> {
public:
    virtual void update() = 0;
};

#endif //LISTA_OBSERVER_H
