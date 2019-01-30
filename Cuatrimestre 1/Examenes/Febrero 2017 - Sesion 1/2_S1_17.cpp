#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


/*
           | c0 si n = 1
    T(n) = |
           | 2T(n/2) + c1 si n > 1
 
 Despliegue: T(n) = 2T(n/2) + c1 = 2^2T(n/2^2) + c1 + c1 = 2^3T(n/2^3) + c1 + 2c1 = ... = 2^kT(n/2^k) + kc1 =
 2^log(n)T(1) + log(n) * c1
 
 n/2^k = 1
 n = 2^k
 log(n) = log(2^k)
 log(n) = k
 */
//Coste O(n)
bool dyv(const std::vector<int> &v, const int &ini, const int &fin) {
    
    if (ini + 1 == fin) return true; //Vector de un elemento.
    
    if (v[ini] == v[fin - 1]) return true; //Si todos los elems del vector son iguales
    
    int m = (ini + fin - 1) / 2;
    
    bool iz = true, dr = true;
    
    if (m > 0 && (v[m - 1] + 1 != v[m] && v[m - 1] != v[m])) return false; //Si el actual no cumple con el anterior devuelvo false directamente.
    else if (m < fin - 1 && (v[m] + 1 != v[m + 1] && v[m] != v[m + 1])) return false; //Si el actual no cumple con el siguiente devuelvo false directamente.
    
    if (v[ini] != v[m]) iz = dyv(v, ini, m + 1); //Compruebo izquierda
    if (v[m + 1] != v[fin - 1]) dr = dyv(v, m + 1, fin); //Compruebo derecha
    
    return iz && dr;
}

void resuelveCaso() {
    int n;
    std::cin >> n;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    if(dyv(v, 0, n))
        std::cout << "SI\n";
    else
        std::cout << "NO\n";
    
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
