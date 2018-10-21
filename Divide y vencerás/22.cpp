//Ejercicio 22
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int calcularPartidos(const std::vector<std::string> &v, const int &pos,
                     const int &jugadores, const int &maxRonda) {
    
    if(maxRonda == 0) return 0;
    
    if (pos + 1 == v.size()) {
        if (v[pos] == "NP") return 0;
        return 1;
    }
    
    int sum = 1;
    
    if (v[pos] != "NP") {
        if (jugadores == 1)
            sum += calcularPartidos(v, pos + 1, 0, maxRonda - 1);
        else
            sum = calcularPartidos(v, pos + 1, jugadores + 1, maxRonda);
    }
    else
        sum = calcularPartidos(v, pos + 1, jugadores + 1, maxRonda);
    //int sum = calcularPartidos(v, pos + 1, ronda);
    //if (v[pos] != "NP" ) return sum + 1;
    
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
    
    std::cout << calcularPartidos(v, 0, 0, numRondas) << "\n";
    
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

