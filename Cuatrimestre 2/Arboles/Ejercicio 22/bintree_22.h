//
//  bintree_22.h
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
    
    int diametro() const{
        int alt = 0;
        return 1 + diametro(this->raiz, alt);
        
    }
    
    
private:
    
    int diametro(Link r, int &altura) const{
        if (r == nullptr) return -1;
        
        int alturaIz = altura, alturaDr = altura;
        int diamIzq = diametro(r->left, alturaIz);
        int diamDr = diametro(r->right, alturaDr);
        
        int diam = std::max(std::max(diamIzq, diamDr), alturaIz + alturaDr);
        altura = 1 + std::max(alturaIz, alturaDr);
        
        return diam;
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
