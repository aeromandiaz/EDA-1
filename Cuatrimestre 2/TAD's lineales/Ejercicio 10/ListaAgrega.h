//
//  ListaAgrega.h
//  ProblemasEDA
//
//  Created by Mauri on 16/02/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef ListaAgrega_h
#define ListaAgrega_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class ListaAgrega : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
    
public:
    
    void agregarEnPos(ListaAgrega<T> &listaNueva, const int &pos) {
        Nodo * nodoActual = this->prim;
        
        for (int i = 0; i < pos - 1 && nodoActual->sig != nullptr; ++i)
            nodoActual = nodoActual->sig;
        
        Nodo * tmp = nodoActual->sig;
        if (pos == 0) {
            if (nodoActual->sig == nullptr)
                this->ult = nodoActual;
            listaNueva.ult->sig = nodoActual;
            nodoActual = listaNueva.prim;
            this->prim = nodoActual;
        } else {
            nodoActual->sig = listaNueva.prim;
            listaNueva.ult->sig = tmp;
            if (tmp == nullptr)
                this->ult = listaNueva.ult;
        }
        
        this->nelems = this->nelems + listaNueva.size();
        listaNueva.nelems = 0;
        listaNueva.prim = nullptr;
        listaNueva.ult = nullptr;
    }
        
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaAgrega<T> & data) {
    
    for (size_t i = 0; i < data.size(); i++) {
        int temp = data.front();
        o << temp << " ";
        data.push(temp);
        data.pop();
    }
    
    return o;
}


#endif /* ListaAgrega_h */
