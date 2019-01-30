//Ejercicio 22
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using tMatriz = std::vector<std::vector<std::string>>;

int calcularPartidos(const std::vector<std::string> &v, const int &pos,
                     const int &ronda, tMatriz &v2) {
    
    if (pos + 1 == v.size()) {
        if (v[pos] != "NP")
            v2[ronda + 1].push_back(v[pos]);
        if (!v2[ronda + 1].empty() && v2[ronda + 1].size() %2 == 0)
            return 1;
        return 0;
    }
    int sum = 0;
    
    if (v[pos] != "NP")
        v2[ronda + 1].push_back(v[pos]);
    if (!v2[ronda].empty() && v2[ronda].size() % 2 == 0)
        ++sum;
    sum += calcularPartidos(v, pos+1, ronda, v2);
    
    return sum;
}


bool resuelveCaso() {
    int n, numRondas;
    std::cin >> n;
    
    if(!std::cin) return false;
    
    std::cin >> numRondas;
    
    std::vector<std::string> v;
    
    for (int i = 0; i < n; ++i) {
        std::string aux;
        std::cin >> aux;
        v.push_back(aux);
    }
    tMatriz aux(numRondas);
    std::cout << calcularPartidos(v, 0, 0, aux) << "\n";
    
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

