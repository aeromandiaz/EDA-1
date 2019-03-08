//Ejercicio 02
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Horas.h"
#include "Pelicula.h"


bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if(n == 0) return false;
    
    std::vector<Pelicula> v;
    
    Pelicula aux;
    for (int i = 0; i < n; ++i) {
        std::cin >> aux;
        v.push_back(aux);
    }
    
    std::sort(v.begin(), v.begin() + n);
    
    
    for (int i = 0; i < n; ++i) {
        try {
            std::cout << v[i] << "\n";
        } catch (std::invalid_argument &ia) {
            std::cout << ia.what() << "\n";
        }
    }
    
    std::cout << "---\n";
    
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
