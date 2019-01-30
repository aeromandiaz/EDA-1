//Ejercicio 21
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

struct caucasico {
    int numPares;
    bool esCaucasico;
};

caucasico operator+(const caucasico & c1, const caucasico &c2) {
    return {c1.numPares + c2.numPares, std::abs(c1.numPares - c2.numPares) <= 2};
}

/*
        | c0 si n = 1
 T(n) = |
        | 2T(n/2) + c0 si n > 1
 
 Despligue:
 T(n) = 2T(n/2) + c0 = 2^2T(n/(2^2)) + 2c0 + c = 2^3T(n/(2^3)) + 2^2c0 + c0 = ... =
 = 2^kT(n/(2^k)) + 2*kc0 + 2^(k-1)c0 + 2^(k-2)c0 + ... + 2^2c0 + 2c0 + 2^0c0
 
 Coste: O(n)
 */
caucasico esCaucasico(const std::vector<unsigned int> &v, const int &ini, const int &fin) {
    if (ini + 1 == fin) { //Vector de un elemento.
        if (v[ini] % 2 == 0) return {1, true};
        else return {0, false};
    }
    
    int m = (ini + fin - 1) / 2;
    caucasico iz, dr, resultado;
    
    iz = esCaucasico(v, ini, m + 1);
    if (iz.numPares != 0 && !iz.esCaucasico) return {iz.numPares, false};
    dr = esCaucasico(v, m+1, fin);
    if (dr.numPares != 0 && !dr.esCaucasico) return {iz.numPares + dr.numPares, false};
    
    resultado = iz + dr;
    
    return resultado;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if(n == 0) return false;
    
    std::vector<unsigned int> v;
    
    for (int i = 0; i < n; ++i) {
        unsigned int aux;
        std::cin >> aux;
        v.push_back(aux);
    }
    
    if (n == 1 || esCaucasico(v, 0, n).esCaucasico)
        std::cout << "SI\n";
    else
        std::cout << "NO\n";
    
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
    
    return 0;
}

