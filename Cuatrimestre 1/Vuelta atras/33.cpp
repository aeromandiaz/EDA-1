//Ejercicio 33
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

void vueltaAtras(const std::vector<int> &costes, const std::vector<int> &espacio, std::vector<bool> &sol,
                 const int &k, const int &n, const int &p, int superficie, int costeAc, int &mejorValor){
    
    sol[k] = true;
    costeAc += costes[k];
    superficie += espacio[k];
    if(costeAc <= p) {
        if(k + 1 == n) {
            if(mejorValor < superficie){
                mejorValor = superficie;
                //for (int z = 0; z < n; ++z) solMejor[z] = sol[z];
            }
        }
        else
            vueltaAtras(costes, espacio, sol, k + 1, n, p, superficie, costeAc, mejorValor);
    }
    costeAc -= costes[k];
    superficie -= espacio[k];
    sol[k] = false;
    if(k + 1 == n) {
        if(mejorValor < superficie){
            mejorValor = superficie;
            //for (int z = 0; z < n; ++z) solMejor[z] = sol[z];
        }
    }
    else
        vueltaAtras(costes, espacio, sol, k + 1, n, p, superficie, costeAc, mejorValor);
}


bool resuelveCaso() {
    int n, p;
    std::cin >> n >> p;
    
    if(!std::cin) return false;
    
    std::vector<int>costes(n, 0), espacio(n, 0);
    std::vector<bool> marcas(n, false);
    
    for (int i = 0 ; i < n; ++i)
        std::cin >> costes[i];
    for (int i = 0 ; i < n; ++i)
        std::cin >> espacio[i];
    
    std::vector<bool> sol(n);
    int valorMejor = 0;
    
    
    vueltaAtras(costes, espacio, sol, 0, n, p, 0, 0, valorMejor);
    
    std::cout << valorMejor << "\n";
    
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
