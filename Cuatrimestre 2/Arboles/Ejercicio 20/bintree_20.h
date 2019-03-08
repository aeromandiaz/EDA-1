//
//  bintree_20.h
//  ProblemasEDA
//
//  Created by Mauri on 08/03/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef bintree_20_h
#define bintree_20_h

#include <iostream>
#include <algorithm>
#include "bintree_eda.h"

template<class T>
class bintreePlus: public bintree<T> {
    using Link = typename bintree<T>::Link;
    
public:
    
    bintreePlus() : bintree<T>() {}
    
    bintreePlus(bintreePlus<T> const& l, T const& e, bintreePlus<T> const& r) : bintree<T>(l, e, r) {}
    
    std::vector<T> frontera() const {
        std::vector<T> sol;
        frontera(sol, this->raiz);
        return sol;
    }
    
    
private:
    
    void frontera(std::vector<T> &sol, Link r) const {
        if (r == nullptr) return;
        
        if (r->left == nullptr && r->right == nullptr)
            sol.push_back(r->elem);
        else if (r->left == nullptr && r->right != nullptr)
            frontera(sol, r->right);
        else if (r->left != nullptr && r->right == nullptr)
            frontera(sol, r->left);
        else {
            frontera(sol, r->left);
            frontera(sol, r->right);
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


#endif /* bintree_20_h */
