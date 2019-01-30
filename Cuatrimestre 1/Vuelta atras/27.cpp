//Ejercicio 27
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector<std::vector<int>>;

void vueltaAtras(int k, const tMatriz &matriz, const int &n, int acumulado, int &mejorSol, std::vector<bool> &marcas){
    for (int i =0; i < n; i++) {
        acumulado += matriz[k][i];
        if (!marcas[i]) {
            if (k == n - 1) { //Es solución
                if (acumulado < mejorSol) //Hay una mejor solución que la actual.
                    mejorSol = acumulado;
            } else {
                marcas[i] = true;
                vueltaAtras(k + 1, matriz, n, acumulado, mejorSol, marcas);
                marcas[i] = false;
            }
        }
        acumulado -= matriz[k][i];
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
        for (int j=0; j< n; ++j) {
            std::cin >> mat[i][j];
            mejorSol += mat[i][j];
        }
    }
    
    vueltaAtras(0, mat, n, 0, mejorSol, marcas);
    
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
