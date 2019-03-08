//Ejercicio 16A
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <string>


bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if (!std::cin) return false;
    
    std::list<std::string> lEntrada;
    std::stack<std::string> coches;
    std::stack<std::string> carril;
    
    std::string aux;
    for (int i = 0; i < n; ++i) {
        std::cin >> aux;
        lEntrada.push_back(aux);
    }
    
    for (int i = 0; i < n; ++i) {
        std::cin >> aux;
        coches.push(aux);
    }
    
    int sol = 0;
    auto it = lEntrada.cbegin();
    while (it != lEntrada.cend()){
        while (!coches.empty()){
            if (*it == coches.top()){
                coches.pop();
                ++it;
            }
            else if (!carril.empty() && carril.top() == *it){
                carril.pop();
                ++it;
            }
            else {
                carril.push(coches.top());
                coches.pop();
                ++sol;
            }
        }
        while (!carril.empty() && carril.top() == *it) {
            carril.pop(); ++it;
        }
        while (!carril.empty()){
            coches.push(carril.top());
            carril.pop();
        }
    }
    
    std::cout << sol << "\n";
    
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
