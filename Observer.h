//
// Created by Marco De Stefano on 15/04/21.
//

#ifndef LISTA_OBSERVER_H
#define LISTA_OBSERVER_H
#include <memory>
class Subject;

class Observer{
public:
virtual void update(Subject* sub)=0;
virtual void attach()=0;
virtual void detach()=0;
virtual ~Observer(){};
};
#endif //LISTA_OBSERVER_H
