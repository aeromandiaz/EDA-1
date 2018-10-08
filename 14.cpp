//Ejercicio 13
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>


//        | c0 si n == 1
// T(n)   |
//        | 2T(n/2) + c0 si n > 1
//
//    Despliegue:
//    T(n) = 2T(n/2) + c0 = 2^2T(n/(2^2)) + 2c0 + c0 = 2^3T(n/(2^3)) + 2^2c0 + c0 =...
//    = 2^kT(n/(2^k)) + 2*kc0 + 2^(k-1)c0 + 2^(k-2)c0 + ... + 2^(k-n)c0
//
//Coste O(n)
int esDegradado(const std::vector<int> &v, const int &ini, const int &fin) {
    if (ini + 1 >= fin - 1) //Vector de dos elementos
        return v[ini] + v[fin - 1];
    
    int m = (ini + fin - 1) / 2;
    return esDegradado(v, ini, m + 1) + esDegradado(v, m + 1, fin);
}

bool resuelveCaso() {
    
    int n, m;
    bool vectorDegradado = true;
    std::cin >> n;
    
    if (!std::cin) return false;

    std::cin >> m;
    std::vector<int> v;
    
    for (int f = 0; f < m * n; ++f) {
        int aux;
        std::cin >> aux;
        v.push_back(aux);
    }
        
    if (v.size() > 1) {
        for (int i = 0; i < n &&  vectorDegradado; ++i)
            vectorDegradado = esDegradado(v, m * i, (m * (i+1)) / 2) < esDegradado(v, ((m * (i+1)) / 2), (m * (i+1)));
    }
    
    
    if (vectorDegradado) std::cout << "SI\n";
    else std::cout << "NO\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif*/
    
    while (resuelveCaso());
    
    
    // Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/
    
    return 0;
}

