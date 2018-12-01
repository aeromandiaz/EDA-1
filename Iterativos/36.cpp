//Ejercicio 36
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

void resuelve(std::vector<int> &v, const int &n) {
    
    int aux = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] % 2 == 0) {
            v[aux] = v[i];
            ++aux;
        }
    }
    v.resize(aux);
}

void resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    resuelve(v, n);
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i != n - 1)
            std::cout << " ";
    }
    
    std::cout << "\n";
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
    
    for (int i = 0; i < n; ++i)
        resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}
