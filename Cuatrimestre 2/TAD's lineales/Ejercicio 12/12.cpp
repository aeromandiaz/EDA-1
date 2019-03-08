//Ejercicio 12
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "queue_eda.h"


bool resuelveCaso() {
    
    int n, salto;
    std::cin >> n >> salto;
    
    if (n == 0 && salto == 0) return false;
    
    queue<int> alumnos;
    
    for (int i = 0; i < n; ++i)
        alumnos.push(i+1);
    
    int saltaAlumno = salto, tmp;
    while (alumnos.size() > 1) {
        tmp = alumnos.front(); alumnos.pop();
        if (saltaAlumno > 0) {
            alumnos.push(tmp);
            --saltaAlumno;
        } else
            saltaAlumno = salto;
    }
    
    std::cout << alumnos.front() << '\n';
    
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
