//Ejercicio 15
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <queue>
#include <deque>

bool resuelveCaso() {
    
    int n, k;
    std::cin >> n >> k;
    
    if (n == 0 && k == 0) return false;
    
    int tmp;
    int maxCantidad = std::numeric_limits<int>::min();
    
    if(k != 1) {
        std::queue<int> cola;
        std::deque<int> aux;
        for(int i = 0; i < n; ++i) {
            std::cin >> tmp;
            if(i < k) {
                if(maxCantidad < tmp) {
                    aux.clear();
                    maxCantidad = tmp;
                } else {
                    while (!aux.empty() && aux.back() < tmp)
                        aux.pop_back();
                    aux.push_back(tmp);
                }
                cola.push(tmp);
            }
            else{
                std::cout << maxCantidad << " ";
                if(maxCantidad == cola.front()) {
                    maxCantidad = aux.front();
                    aux.pop_front();
                }
                cola.pop();
                cola.push(tmp);
                if(maxCantidad < tmp) {
                    aux.clear();
                    maxCantidad = tmp;
                } else {
                    while (!aux.empty() && aux.back() < tmp)
                        aux.pop_back();
                    aux.push_back(tmp);
                }
            }
        }
        std::cout << maxCantidad;
    }
    else{
        for(int i = 0; i < n; ++i) {
            std::cin >> tmp;
            if(i == 0) std::cout << tmp;
            else std::cout << " " << tmp;
        }
    }
    
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
