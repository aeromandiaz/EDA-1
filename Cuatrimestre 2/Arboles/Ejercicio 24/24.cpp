//Ejercicio 24
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include "bintree_eda.h"

bintree<int> construyeArbol(const std::vector<int> &preorden, const std::vector<int> &inorden, int ini,
                            int fin, std::unordered_map<int, int> &map, int &indexPreorden) {
    if (ini > fin)
        return {};
    
    int elem = preorden[indexPreorden++];
    
    if (ini == fin)
        return {bintree<int>(), elem, bintree<int>()};
    
    int m = map[elem];
    
    auto iz = construyeArbol(preorden, inorden, ini, m - 1, map, indexPreorden);
    auto dr = construyeArbol(preorden, inorden, m + 1, fin, map, indexPreorden);
    
    return {iz, elem, dr};
}

bintree<int> resuelve(const std::vector<int> &preorden, const std::vector<int> &inorden, int tam) {
    int ind = 0;
    std::unordered_map<int, int> map;
    for (int i = 0; i < tam; i++)
        map[inorden[i]] = i;
    
    return construyeArbol(preorden, inorden, 0, tam - 1, map, ind);
}

bool resuelveCaso() {
    std::vector<int> preorden, inorden;
    
    std::string linea;
    getline(std::cin, linea);
    
    if (!std::cin) return false;
    
    std::stringstream ss(linea);
    
    int valor;

    while (ss >> valor)
        preorden.push_back(valor);
    
    getline(std::cin, linea);
    std::stringstream ss2(linea);
    
    while (ss2 >> valor)
        inorden.push_back(valor);
    
    auto arbol = resuelve(preorden, inorden, preorden.size());
    
    auto sol = arbol.postorder();
    
    std::cout << sol[0];
    for (int i = 1; i < sol.size(); ++i)
        std::cout << " " << sol[i];
    
    std::cout << "\n";
    
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
    
}
