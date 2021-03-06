//Ejercicio 46
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector<std::vector<int>>;

int resolver(tMatriz const& mat) {
    
    int res = 0;
    
    for (int f = 0; f < mat.size(); ++f) {
        for (int c = 0; c < mat[f].size(); ++c)
            if (mat[f][c] == f) ++res;
    }
    
    return res;
}

bool resuelveCaso() {
    
    int f, c;
    std::cin >> f >> c;
    
    if (!std::cin) return false;
    
    tMatriz mat(f, std::vector<int>(c));
    
    for (int i = 0; i < f; ++i) {
        for (int n = 0; n < c; ++n)
            std::cin >> mat[i][n];
    }
    
    
    std::cout << resolver(mat) << "\n";
    
    return true;
}

int main(){
    
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
