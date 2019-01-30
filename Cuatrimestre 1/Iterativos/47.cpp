//Ejercicio 47
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector<std::vector<int>>;

int resolver(tMatriz const& mat, const int &f, const int &c, const int &k, const int &y, const int &x) {
    
    int res = 0, contCeros = 0, contFranjas = 0, contCols = 0;
    
    for (int j = 0; j < c; ++j) {
        contCeros = 0;
        int i;
        for (i = 0; i < f; ++i) {
            if (mat[i][j] == 0) ++contCeros;
        }
        
        ++contFranjas;
        
        if (contCeros >= x) ++contCols;
        
        if (contFranjas == k) {
            if (contCols >= y) ++res;
            if(i != f - 1 && j != c - 1)
                j = j - k + 1;
            contCols = 0;
            contFranjas = 0;
        }
    }

    
    return res;
}

bool resuelveCaso() {
    
    int f, c, k, y, x;
    std::cin >> f >> c >> k >> y >> x;
    
    if (!std::cin) return false;
    
    tMatriz mat(f, std::vector<int>(c));
    
    for (int i = 0; i < f; ++i) {
        for (int n = 0; n < c; ++n)
            std::cin >> mat[i][n];
    }
    
    
    std::cout << resolver(mat, f, c, k, y, x) << "\n";
    
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
