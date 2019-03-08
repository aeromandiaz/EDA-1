//Ejercicio 13
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <limits>
#include "queue_eda.h"

bool resuelveCaso() {
    
    int R, N;
    std::cin >> R;
    
    if (!std::cin) return false;
    
    queue<int> clave;
    std::vector<int> mensaje;
    
    int tmp;
    
    for (int i = 0; i < R; ++i) {
        std::cin >> tmp;
        clave.push(tmp);
    }
    
    std::cin >> N;
    
    for (int i = 0; i < N; ++i) {
        std::cin >> tmp;
        mensaje.push_back(tmp);
    }
    
    const int ini = clave.front(), MAX = std::numeric_limits<int>::max();
    int sol = MAX, aux = 0, solAux = 0, zTemporal = MAX;
    
    for (int z = 0; z < N; ++z) {
        if (aux == 1 && ini == mensaje[z])
            solAux = 0;
        else if (aux != 0 && ini == mensaje[z] && zTemporal == MAX)
            zTemporal = z;
        if (clave.front() == mensaje[z]) {
            if (aux == 0)
                solAux=0;
            clave.push(clave.front()); clave.pop();
            ++aux;
        }
        
        ++solAux;
        
        if(sol <= solAux && zTemporal != MAX) {
            aux=0;
            z = zTemporal - 1;
            zTemporal = MAX;
        }
        if(aux == R) {
            sol = std::min(sol,solAux);
            aux = 0;
            if(zTemporal != MAX)
                z = zTemporal - 1;
            zTemporal = MAX;
        }
    }
    
    std::cout << sol << '\n';
    
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
