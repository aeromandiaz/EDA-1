//Ejercicio 18
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include "ArbolGeneralBecarios.h"


bool resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    if (!std::cin) return false;
    
    gTreeEsclavos arbol = leerArbol(0);
    
    std::cout << arbol.numBecarios(n) << "\n";
    
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
