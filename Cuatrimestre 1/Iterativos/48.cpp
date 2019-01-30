//Ejercicio 48
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector<std::vector<int>>;

int resolver(tMatriz const& mat, const int &p) {
    
    tMatriz aux = mat;
    int maximo = mat[0][0];
    
    for(int c = 0 ; c < mat[0].size(); ++c)
        for(int f = 1 ; f < p; ++f)
            aux[f][c] += aux[f-1][c];
    
    for(int c = 0 ; c < mat[0].size() ; ++c) {
        for(int f = p ; f < mat.size() ; ++f) {
            aux[f][c] -= mat[f-p][c];
            aux[f][c] += aux[f-1][c];
        }
    }
    tMatriz matSol = aux;
    
    for(int f = p - 1; f < matSol.size(); ++f) {
        for(int c = 1 ; c < p ; ++c) {
            matSol[f][c] += matSol[f][c-1];
            if(matSol[f][c] > maximo)
                maximo = matSol[f][c];
        }
    }
    
    for(int f = p - 1; f < matSol.size(); ++f) {
        for(int c = p ; c < matSol[0].size() ; ++c) {
            matSol[f][c] -= aux[f][c-p];
            matSol[f][c] += matSol[f][c-1];
            if(matSol[f][c] > maximo)
                maximo = matSol[f][c];
        }
    }
    
    return maximo;
}

bool resuelveCaso() {
    
    int n, p;
    std::cin >> n >> p;
    
    if (!std::cin) return false;
    
    tMatriz mat(n, std::vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < n; ++c)
            std::cin >> mat[i][c];
    }
    
    
    std::cout << resolver(mat, p) << "\n";
    
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
