//Ejercicio 11
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "ListaMerge.h"


void resuelveCaso() {
    
    ListaMerge<int> lista1, lista2;
    int tmp;
    
    std::cin >> tmp;
    
    while (tmp != 0) {
        lista1.push(tmp);
        std::cin >> tmp;
    }
    
    std::cin >> tmp;
    
    while (tmp != 0) {
        lista2.push(tmp);
        std::cin >> tmp;
    }
    
    
    lista1.merge(lista2);
    
    std::cout << lista1 << '\n';
}

int main() {
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
