//
// Created by Marco De Stefano on 15/04/21.
//

#ifndef LISTA_OBSERVER_H
#define LISTA_OBSERVER_H

class Observer{
public:
virtual void Update()=0;
virtual void attach()=0;
virtual void dettach()=0;
virtual ~Observer(){};
};
#endif //LISTA_OBSERVER_H
