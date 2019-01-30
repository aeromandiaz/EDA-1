//Ejercicio 23
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>


bool moviles(int &peso) {
    bool iz = true, dr = true;
    int pi, di, pd, dd;
    
    std::cin >> pi >> di >> pd >> dd ;
    
    if (pi == 0) iz = moviles(pi);
    if (pd == 0) dr = moviles(pd);
    peso = pi + pd;

    return iz && dr && ((pi * di) == (pd * dd));
}

void resuelveCaso() {
    int peso = 0;
    if(moviles(peso))
        std::cout << "SI\n";
    else
        std::cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    int n = 0;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
        resuelveCaso();
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
    return 0;
}

