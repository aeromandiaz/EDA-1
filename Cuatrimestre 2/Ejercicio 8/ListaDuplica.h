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
#include "queue_eda.h"

template <class T>
class ListaDuplica : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
    
public:
    
    void duplicar() {
        Nodo * aux = this->prim;
        
        while (aux != nullptr) {
            Nodo *nuevo = new Nodo(aux->elem, aux->sig);
            if (nuevo->sig == nullptr)
                this->ult = nuevo;
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
        data.push(temp);
        data.pop();
    }
    
    return o;
}


#endif /* ListaDuplica_h */
