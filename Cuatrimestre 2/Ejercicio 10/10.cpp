//Ejercicio 10
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "ListaAgrega.h"


bool resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    if (!std::cin) return false;
    
    ListaAgrega<int> lista;
    int tmp;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        lista.push(tmp);
    }
    
    int m, pos;
    std::cin >> m >> pos;
    
    ListaAgrega<int> listaNueva;
    
    for (int i = 0; i < m; ++i) {
        std::cin >> tmp;
        listaNueva.push(tmp);
    }
    
    lista.agregarEnPos(listaNueva, pos);
    
    std::cout << lista << '\n';
    
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
