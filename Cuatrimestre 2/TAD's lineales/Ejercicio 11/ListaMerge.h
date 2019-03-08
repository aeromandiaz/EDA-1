//
//  ListaMerge.h
//  ProblemasEDA
//
//  Created by Mauri on 16/02/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef ListaMerge_h
#define ListaMerge_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class ListaMerge : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
    
public:
    
    void merge(ListaMerge<T> &lista2) {
        this->prim = MezclaOrdenada(this->prim, lista2.prim, lista2.ult);
        this->nelems = this->nelems + lista2.size();
        lista2.prim = nullptr;
        lista2.ult = nullptr;
        lista2.nelems = 0;
    }
    
private:
    
    Nodo* MezclaOrdenada(Nodo * a, Nodo * b, Nodo * ult) {
        Nodo * resultado = nullptr;
        
        if (a == nullptr) {
            this->ult = ult;
            return b;
        } else if (b == nullptr)
            return a;
        
        if (a->elem <= b->elem) {
            resultado = a;
            resultado->sig = MezclaOrdenada(a->sig, b, ult);
        }
        else {
            resultado = b;
            resultado->sig = MezclaOrdenada(a, b->sig, ult);
        }
        return resultado;
    }
        
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaMerge<T> & data) {
    
    for (size_t i = 0; i < data.size(); i++) {
        int temp = data.front();
        o << temp << " ";
        data.push(temp);
        data.pop();
    }
    
    return o;
}


#endif /* ListaMerge_h */
