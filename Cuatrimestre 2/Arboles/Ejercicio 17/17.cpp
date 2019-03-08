//Ejercicio 17
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>

int calcularAltura() {
    
    int hijos;
    std::cin >> hijos;
    
    if (hijos == 0) return 1;
    else {
        int altura = 1, aux;
        
        for (int i = 0; i < hijos; ++i) {
            aux = calcularAltura();
            if (aux > altura)
                altura = aux;
        }
        return altura + 1;
        
    }
}


bool resuelveCaso() {
    
    std::cout << calcularAltura() << '\n';
    
    return true;
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
    
    for (int i = 0; i < n; ++i) resuelveCaso();
     
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
