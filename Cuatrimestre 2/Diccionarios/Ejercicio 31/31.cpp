//Ejercicio 31
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

bool resuelveCaso() {
    
    int n;
    std::cin >> n;
    std::cin.get();
    
    if (n == 0)
        return false;
    
    std::string linea;
    std::string clave;
    std::map<std::string, std::vector<int>> m;
    
    for (int i = 1; i <= n; ++i){
        getline(std::cin, linea);
        std::stringstream v(linea);
        while (v >> clave) {
            for (int t = 0; t < clave.size(); t++) clave[t] = tolower(clave[t]);
            if (clave.size() > 2) {
                if (m[clave].size() > 0 && m[clave][m[clave].size() - 1] != i)
                    m[clave].push_back(i);
                else if (m[clave].size() == 0)
                    m[clave].push_back(i);
            }
        }
    }
    
    for (auto &it : m){
        std::cout << it.first;
        for (int i = 0; i < it.second.size(); ++i)
            std::cout << " " << it.second[i];
        std::cout << "\n";
    }
    
    std::cout << "----\n";
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
