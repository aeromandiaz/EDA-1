//Ejercicio 30
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using tMatriz = std::vector<std::vector<int>>;

void vueltaAtras(int k, const tMatriz &matriz, const int &n, std::vector<int> &acumulado,
                 int tiempo, int &mejorSol, std::vector<bool> &marcas){
    
    for (int i = 0; i < n; ++i) {
        if (!marcas[i]) {
            tiempo += matriz[k][i];
            int tiempoEstimado = tiempo + acumulado[k];
            if (tiempoEstimado < mejorSol){
                if (k == n - 1) { //Es solución
                    mejorSol = tiempoEstimado;
                } else {
                    marcas[i] = true;
                    vueltaAtras(k + 1, matriz, n, acumulado, tiempo, mejorSol, marcas);
                    marcas[i] = false;
                }
            }
            tiempo -= matriz[k][i];
        }
    }
}


bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if(n == 0) return false;
    
    int mejorSol = 0;
    tMatriz mat(n, std::vector<int>(n));
    std::vector<bool> marcas(n, false);
    
    for (int i=0 ; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            std::cin >> mat[i][j];
            mejorSol += mat[i][j];
        }
    }
    std::vector<int> minimo(n), acumulado(n);
    
    for (int i = 0 ; i < n; ++i) {
        minimo[i] = mat[i][0];
        for (int j = 1; j < n; ++j) {
            minimo[i] = std::min(minimo[i], mat[i][j]);
        }
    }
    
    acumulado[n - 1] = 0;
    
    for (int i = n - 2; i >= 0; --i) {
        acumulado[i] = acumulado[i + 1] + minimo[i + 1];
    }
    
    vueltaAtras(0, mat, n, acumulado, 0, mejorSol, marcas);
    
    std::cout << mejorSol << "\n";
    
    return true;
}

int main(){
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while ( resuelveCaso());
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}
