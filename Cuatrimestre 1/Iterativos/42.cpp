//Ejercicio 42
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

int resolver(std::vector<int> const& v) {
    
    int pos = -1, numCeros = 0, numUnos = 0;
    
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) ++numCeros;
        else if (v[i] == 1) ++numUnos;
        if (numUnos == numCeros) pos = i;
    }
    
    return pos;
}

void resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    std::vector<int>v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    
    std::cout << resolver(v) << "\n";
    
}

int main(){
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    int n;
    std::cin >> n;

    for(int i = 0;i < n; ++i)
        resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}
