//Ejercicio 21
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_21.h"


bool resuelveCaso() {
    
    char tipo;
    std::cin >> tipo;
    
    if(!std::cin) return false;
    
    if (tipo == 'N') {
        bintreePlus<int> arbol = leerArbolPlus(-1);
        std::cout << arbol.minElem() << "\n";
    }
    else {
        std::string fin = "#";
        bintreePlus<std::string> arbol = leerArbolPlus(fin);
        std::cout << arbol.minElem() << "\n";
    }
    
    return true;
}

int main() {
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    while(resuelveCaso());
     
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
