//
//  ArbolGeneralBecarios.h
//  ProblemasEDA
//
//  Created by Mauri on 08/03/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef ArbolGeneralBecarios_h
#define ArbolGeneralBecarios_h

#include <iostream>
#include <algorithm>
#include "ArbolGeneral.h"

class gTreeEsclavos: public gTree<int> {
    
public:
    
    gTreeEsclavos(int const &e): gTree(e) {}
    
    gTreeEsclavos(int const &e, std::vector<gTree<int>> const &r): gTree(e, r){}
    
    int numBecarios(int altura) {
        return numBecarios(raiz, altura);
    }
    
private:
    
    int numBecarios (Link ptr, int altura) {
        if(ptr->st.empty()) {
            if (altura <= 0) return 1;
            else return 0;
        } else {
            int m = 0;
            
            for (int i = 0; i < ptr->st.size(); ++i)
                m += numBecarios(ptr->st[i], altura - 1);
            
            return m;
        }
    }
    
};

inline gTreeEsclavos leerArbol(int vacio){
    
    int raiz;
    std::cin >> raiz;
    
    if (raiz == vacio)
        return gTreeEsclavos(raiz);
    else {
        std::vector<gTree<int>> v;
        for (int i =0 ; i< raiz; ++i) {
            auto subtree = leerArbol(vacio);
            v.push_back(subtree);
        }
        return gTreeEsclavos(raiz, v);
    }
}


#endif /* ArbolGeneralPLUS_h */
