//Ejercicio 12
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>


bool esDisperso(const std::vector<int> &v, const int &ini, const int &fin, const int &indice) {
    if (ini + 1 == fin) return  true; //Vector de un elemento
    else if (ini + 2 == fin) //Vector dos elementos
        return indice <= std::abs(v[ini +1] - v[ini]);
    
    int m = (ini + fin) / 2;
    bool  iz = esDisperso(v, ini, m, indice);
    bool  dr = esDisperso(v, m, fin, indice);
    return  iz && dr && indice <= std::abs(v[ini] - v[fin - 1]);
}

bool resuelveCaso() {
    
    int n, disp;
    std::cin >> n;
    
    if (!std::cin) return false;
    
    std::cin >> disp;
    
    std::vector<int> v;
    
    for (int i = 0; i < n; ++i) {
        unsigned int aux;
        std::cin >> aux;
        v.push_back(aux);
    }
    
    if (esDisperso(v, 0, v.size(), disp)) std::cout << "SI\n";
    else std::cout << "NO\n";
    
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
    system("PAUSE");
#endif
    
    return 0;
}
