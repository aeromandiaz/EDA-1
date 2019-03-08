//
//  ListaDuplica.h
//  ProblemasEDA
//
//  Created by Mauri on 15/02/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef ListaDuplica_h
#define ListaDuplica_h

#include <iostream>
#include "deque_eda.h"

template <class T>
class ListaDuplica : public deque<T> {
    using Nodo = typename deque<T>::Nodo;
    
public:
    
    void duplicar() {
        Nodo * aux = this->fantasma->sig;
        
        for (int i = 0; i < this->nelems; ++i) {
            Nodo *nuevo = new Nodo(aux->elem, aux, aux->sig);
            aux->sig->ant = nuevo;
            aux->sig = nuevo;
            aux = aux->sig->sig;
        }
        
        this->nelems = this->nelems * 2;
    }
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaDuplica<T> & data) {
    
    for (size_t i = 0; i < data.size(); i++) {
        int temp = data.front();
        o << temp << " ";
        data.push_back(temp);
        data.pop_front();
    }
    
    return o;
}


#endif /* ListaDuplica_h */
