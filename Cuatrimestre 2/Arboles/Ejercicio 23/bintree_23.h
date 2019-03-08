//
//  bintree_23.h
//  ProblemasEDA
//
//  Created by Mauri on 08/03/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef bintree_21_h
#define bintree_21_h

#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

template<class T>
class bintreePlus: public bintree<T> {
    using Link = typename bintree<T>::Link;
    
public:
    
    bintreePlus() : bintree<T>() {}
    
    bintreePlus(bintreePlus<T> const& l, T const& e, bintreePlus<T> const& r) : bintree<T>(l, e, r) {}
    
    void planificarRescate(int &grupos, int &max){
        planificarRescate(this->raiz, grupos, max);
    }
    
    
private:
    
    void planificarRescate(Link r, int &grupos, int &max){
        int gruIzq, maxIzq, gruDer, maxDer;
        
        if (r == nullptr) {
            grupos = 0;
            max = 0;
        }
        
        else {
            planificarRescate(r->left, gruIzq, maxIzq);
            planificarRescate(r->right, gruDer, maxDer);
            
            if (gruIzq == 0 && gruDer == 0 && r->elem != 0)
                grupos = 1;
            else
                grupos = gruDer + gruIzq;
            
            if (maxIzq > maxDer)
                max = maxIzq + r->elem;
            else
                max = maxDer + r->elem;
        }
        
    }
};

template <class T>
inline bintreePlus<T> leerArbolPlus(T vacio){
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) {
        return {};
    } else {
        auto iz = leerArbolPlus(vacio);
        auto dr = leerArbolPlus(vacio);
        return {iz, raiz, dr};
    }
}


#endif /* bintree_21_h */
