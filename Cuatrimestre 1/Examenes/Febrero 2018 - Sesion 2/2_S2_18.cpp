#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


/*
           | c0 si n = 1
    T(n) = |
           | T(n/2) + c1 si n > 1
 
 Despliegue: T(n) = T(n/2) + c1 = T(n/2^2) + c1 + c1 = T(n/2^3) + c1 + 2c1 = ... = T(n/2^k) + kc1 =
 T(1) + log(n) * c1
 
 n/2^k = 1
 n = 2^k
 log(n) = log(2^k)
 log(n) = k
 */
//Coste O(log(n))
int dyv(const std::vector<int> &v, const int &ini, const int &fin, int x) {
    
    if (ini + 1 == fin) return v[ini];
    
    int m = (ini + fin - 1) / 2;
    
    if (v[m] == x) return v[m];
    else if (std::abs(x - v[m]) <=  std::abs(x - v[m + 1])) return dyv(v, ini, m + 1, x);
    else return dyv(v, m + 1, fin, x);
    
    return 0;
}

void resuelveCaso() {
    int x, n;
    std::cin >> x >> n;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    std::cout << dyv(v, 0, n, x) << "\n";
    
}

int main(){
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
