//Ejercicio 37
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

bool resuelve(const std::vector<int> &v, const int &n, const int &p) {
    int maxAnteriorDeP = v[0], menorPosteriorDeP;
    
    for (int i = 0; i <= p; ++i) {
        if (v[i] > maxAnteriorDeP)
            maxAnteriorDeP = v[i];
    }
    
    if (p + 1 < n)
        menorPosteriorDeP = v[p + 1];
    else
        menorPosteriorDeP = maxAnteriorDeP + 1;

    for (int i = p + 1; i < n; ++i) {
        if (v[i] < menorPosteriorDeP)
            menorPosteriorDeP = v[i];
    }

    return maxAnteriorDeP < menorPosteriorDeP;
}

void resuelveCaso() {
    
    int n, p;
    std::cin >> n >> p;
    
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    if (resuelve(v, n, p)) std::cout << "SI\n";
    else std::cout << "NO\n";
    
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
