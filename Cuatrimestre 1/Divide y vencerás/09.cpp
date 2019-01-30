//Ejercicio 09
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>

//        | c0 si n == 1
// T(n) |
//        | T(n/2) + c0 si n > 1
//
//    Despliegue:
//    T(n) = T(n/2) + c0 = T(n/(2^2)) + c0 + c0 = T(n/(2^3)) + c0 + c0 + c0 =...
//    = T(n/(2^k)) + k*c0
//    Por tanto, log(n) + n*c0
//
//Coste O(logn)
int elemImpar(const std::vector<int> &v, const int &ini, const int &fin) {
    
    if (ini + 1 == fin) return v[ini];
    
    int m = (ini + fin - 1) / 2;
    
    if (v[m] % 2 != 0) return v[m];
    if ((v[m] - v[ini]) != ((m - ini) * 2)) return elemImpar(v, ini, m);
    else return elemImpar(v, m + 1, fin);
    
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if (n == 0) return false;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    std::cout << elemImpar(v, 0, n) << "\n";
    
    return true;
}

int main(){
    
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
