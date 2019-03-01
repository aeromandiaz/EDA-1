//Ejercicio 16
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include "Persona.h"

class FiltroEdad {
public:
    
    FiltroEdad(int min, int max): minEdad(min), maxEdad(max) {}
    
    bool operator()(Persona const &p) {
        return p.getEdad() >= minEdad && p.getEdad() <= maxEdad;
    }
    
private:
    int minEdad;
    int maxEdad;
};

template <class T, class Predicate>
void remove_if(std::list<T> &lista, Predicate pred) {
    auto it = lista.begin();
    
    while(it != lista.end()) {
        if (!pred(*it))
            it = lista.erase(it);
        else
            ++it;
    }
}

//IMPLEMENTACIÓN CON LISTAS USANDO ITERADORES
bool resuelveCaso() {
    int n, min, max;
    std::cin >> n >> min >> max;
    
    if (n == 0 && min == 0 && max == 0) return false;
    
    std::list<Persona> lista;
    
    Persona aux;
    for (int i = 0; i < n; ++i) {
        std::cin >> aux;
        lista.push_back(aux);
    }
    
    remove_if(lista, FiltroEdad(min, max));
    
    auto it = lista.cbegin();
    
    for (; it != lista.cend(); ++it) {
        std::cout << *it << "\n";
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
    
    while (resuelveCaso());
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
