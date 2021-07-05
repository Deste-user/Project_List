//
// Created by Marco De Stefano on 15/04/21.
//

#ifndef LISTA_SUBJECT_H
#define LISTA_SUBJECT_H
#include "Observer.h"
class Subject{
public:
    virtual void attach(Observer* A )=0;
    virtual void dettach(Observer* B)=0;
    virtual void notify()=0;


};
#endif //LISTA_SUBJECT_H
