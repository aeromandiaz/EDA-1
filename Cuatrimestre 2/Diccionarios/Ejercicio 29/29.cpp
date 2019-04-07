//Ejercicio 29
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

long long int resolver(int capitulos) {
    std::unordered_map<int, int> lista;
    long long int distancia = 0;
    int ini = 1;
    long long int max = 0;
    int elem;
    
    for (int i = 1; i <= capitulos; ++i) {
        std::cin >> elem;
        if (lista[elem] >= ini){
            ini = lista[elem] + 1;
            distancia = i-lista[elem];
        }
        else {
            ++distancia;
            if (distancia > max)
                max = distancia;
        }
        lista[elem] = i;
    }
    return max;
}

void resuelveCaso() {
    
    int capitulos;
    std::cin >> capitulos;
    
    long long int max = resolver(capitulos);
    
    std::cout << max << "\n";
}

int main() {
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i)
        resuelveCaso();
     
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
