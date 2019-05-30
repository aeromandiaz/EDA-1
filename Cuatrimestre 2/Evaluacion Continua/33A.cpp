//Ejercicio 33A
//Mauricio Abbati Loureiro - EDA 2¼E 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using pelis = std::string;
using dias = std::string;

struct tDatos {
    int numReproducciones = 1;
    std::vector<dias> listaDias;
};


bool resuelveCaso() {
    int numDias; 
    std::cin >> numDias;
    if (!std::cin) return false;
    
    // Declaracion de estructuras de datos
    std::map<pelis,tDatos> mapaPeliculas;
    
    int maximo = 0;

    // Bucle de lectura de datos
    for (int i = 0; i < numDias; ++i) {
		dias fecha;
		pelis titulo; 
		int numPeliculas;
        std::cin >> fecha >> numPeliculas;
        std::cin.ignore();
        // Bucle de lectura de las peliculas de cada dia
        for (int i = 0; i < numPeliculas; ++i) {
            getline(std::cin, titulo);
            auto it = mapaPeliculas.find(titulo);
            if (it == mapaPeliculas.cend()) {
                tDatos tmp;
                tmp.listaDias.push_back(fecha);
                maximo = std::max(tmp.numReproducciones, maximo);
                mapaPeliculas[titulo] = tmp;
            } else {
                if (it->second.listaDias[it->second.listaDias.size()-1] != fecha)
                    it->second.listaDias.push_back(fecha);
                it->second.numReproducciones++;
                maximo = std::max(it->second.numReproducciones, maximo);
            }
        }
    }
    
    auto it = mapaPeliculas.cbegin();
    
    std::cout << maximo << "\n";
    
    while (it != mapaPeliculas.cend()) {
        if (it->second.numReproducciones == maximo) {
            std::cout << it->first;
            for (auto &dias: it->second.listaDias)
                std::cout << " " << dias;
            std::cout << "\n";
        }
        it++;
    }

    // Marca de final de caso
    std::cout << "---\n";
    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos
   
    // Para restablecer entrada. 
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
