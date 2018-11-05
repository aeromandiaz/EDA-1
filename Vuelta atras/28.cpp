//Ejercicio 28
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector<std::vector<int>>;

bool esValida(const std::vector<int> &marcas, const int &k) {
    return marcas[k] < 3;
}

void supermercado(std::vector<int> &sol, const int &k, const int &n, const int &p, const tMatriz &costes,  std::vector<int> &contSup, std::vector<int> &minimos, int &coste, int &costeMejor, bool &haySol){
    for (int i = 0; i < n; ++i){
        sol[k] = i;
        if(esValida(contSup, i)){
            coste = coste + costes[i][k];
            contSup[i] = contSup[i]+1;
            if(k + 1 == p){ // Es solución
                if(coste < costeMejor) //Es mejor solución
                    costeMejor = coste;
                haySol = true;
            }
            else{
                if(coste < costeMejor)
                    supermercado(sol, k + 1, n, p, costes, contSup, minimos, coste, costeMejor,haySol);
            }
            coste = coste - costes[i][k];
            contSup[i] = contSup[i]-1;
        }
    }
}


void resuelveCaso() {
    int n, p;
    std::cin >> n;
    std::cin >> p;
    
    tMatriz costes(n, std::vector<int>(3*n));
    std::vector<int> minimos, contSup, sol(3*n);
    
    int costeMejor = 2147483647;
    for(int i = 0; i < n; i++){
        contSup.push_back(0);
        for(int j = 0; j < p; j++){
            std::cin >> costes[i][j];
            if(j == 0)
                minimos.push_back(costes[i][j]);
            else if(costes[i][j] < minimos[i]){
                minimos.push_back(costes[i][j]);
            }
        }
    }
    
    int coste = 0;
    int k = 0;
    bool haySol = false;
    if( n == 0 || p == 0)
        std::cout << 0 << "\n";
    else{
        supermercado(sol, k, n, p, costes, contSup, minimos, coste, costeMejor, haySol);
        if(haySol)
            std::cout << costeMejor << "\n";
        else
            std::cout << "Sin solucion factible\n";
    }
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
