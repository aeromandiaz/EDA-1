//Ejercicio 28
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <map>

bool resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    if (n == 0) return false;
    
    std::map<std::string, int>lista;
    std::string nombre, eval;
    
    for (int i = 0; i < n; ++i) {
        std::cin.ignore();
        getline(std::cin, nombre);
        std::cin >> eval;
        
        if (eval == "INCORRECTO")
            lista[nombre]--;
        else
            lista[nombre]++;
    }
    
    for (auto c : lista) {
        if (c.second != 0)
            std::cout << c.first << ", " << c.second << "\n";
    }
    std::cout << "---\n";
    
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
