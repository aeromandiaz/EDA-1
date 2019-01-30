//Ejercicio 34
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector<std::vector<int>>;

bool esValida(const std::vector<int> &sol, const std::vector<int> &marcas, const int &k, const int &i, const int &maxT){
    
    if (marcas[i] >= maxT) return false;
    if (k > 0 && k % 2 != 0 && sol[k - 1] == sol[k]) return false;
    
    return true;
}

void vueltaAtras(std::vector<int> &sol, int satAc, const int &k, std::vector<int> &marcas,const tMatriz &mat, int &mejorSol, const int &maxT, const int &a, const int &n){
   
    for (int i = 0; i < a; ++i) {
        sol[k] = i;
        satAc += mat[i][k / 2];
        if (esValida(sol, marcas, k, i, maxT)) {
            if (k == (n * 2) - 1) { //Es solucion
                if (satAc > mejorSol) { //Es mejor solucion
                    mejorSol = satAc;
                    //for (int z = 0; z < sol.size(); ++z) sol[z] = aux[z];
                }
            } else {
                ++marcas[i];
                vueltaAtras(sol, satAc, k + 1, marcas, mat, mejorSol, maxT, a, n);
                --marcas[i];
            }
        }
        satAc -= mat[i][k / 2];
    }
}


bool resuelveCaso() {
    int n, a, maxT;
    std::cin >> n >> a >> maxT;
    
    if(n == 0 && a == 0 && maxT == 0) return false;
    
    tMatriz mat(a, std::vector<int>(n));
    
    for (int i = 0; i < a; ++i) {
        for (int c = 0; c < n; ++c)
            std::cin >> mat[i][c];
    }
    
    std::vector<int> sol(n * 2);
    std::vector<int> marcas(a, 0);
    int mejorSol = 0;
    
    vueltaAtras(sol, 0, 0, marcas, mat, mejorSol, maxT, a, n);
    
    std::cout << mejorSol << "\n";
    /*for (int i = 0;i < sol.size(); ++i) {
        std::cout << sol[i] << " ";
    }
    std::cout << "\n";*/

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
