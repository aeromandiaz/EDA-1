//Ejercicio 17
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

//O(logn)
int buscarFaltante(const std::vector<int> &v1, const std::vector<int> &v2, const int &ini, const int &fin) {
    if (ini == fin) return 0; //Vector vacío
    if (ini + 1 == fin) return v1[ini]; //Vector de un elemento
    
    int m= (ini+fin-1) / 2;
    if (v1[m] == v2[m]) return buscarFaltante(v1, v2, m + 1, fin);
	else return buscarFaltante(v1, v2, ini, m + 1);
}

void resuelveCaso() {
    int n;
    
    std::cin >> n;
    std::vector<int> v1;
    std::vector<int> v2;
    
    for (int i = 0; i < n; ++i) {
        int aux;
        std::cin >> aux;
        v1.push_back(aux);
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int aux;
        std::cin >> aux;
        v2.push_back(aux);
    }
    
    std::cout << buscarFaltante(v1, v2, 0, n) << "\n";
    
    
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
    
    for (int i = 0; i < n; ++i)
        resuelveCaso();
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
    return 0;
}

