//
//  bintree_21.h
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
    
    T minElem() const{
        T min;
        minElem(this->raiz, min);
        
        return min;
    }
    
    
private:
    
    void minElem(Link r, T &min) const{
        if(r->left == nullptr && r->right == nullptr)
            min = r->elem;
        else{
            T minIz, minDr;
            if(r->left != nullptr){
                minElem(r->left, minIz);
                min = std::min(r->elem, minIz);
                
                if(r->right != nullptr){
                    minElem(r->right, minDr);
                    min = std::min(min, minDr);
                }
            }
            else{
                minElem(r->right, minDr);
                min = std::min(r->elem, minDr);
            }
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
