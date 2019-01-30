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

void supermercado(std::vector<int> &sol, const int &k, const int &n, const int &p, const tMatriz &costes,  std::vector<int> &marcas, int costeAc, int &costeMejor, bool &haySol){
    for (int i = 0; i < n; ++i){
        sol[k] = i;
        if(esValida(marcas, i)){
            costeAc += costes[i][k];
            ++marcas[i];
            if(k + 1 == p){ // Es solución
                if(costeAc < costeMejor) //Es mejor solución
                    costeMejor = costeAc;
                haySol = true;
            }
            else{
                if(costeAc < costeMejor)
                    supermercado(sol, k + 1, n, p, costes, marcas, costeAc, costeMejor,haySol);
            }
            costeAc -= costes[i][k];
            --marcas[i];
        }
    }
}


void resuelveCaso() {
    int n, p;
    std::cin >> n;
    std::cin >> p;
    
    tMatriz costes(n, std::vector<int>(p));
    std::vector<int> minimos, marcas(n, 0), sol(3*n);
    
    int costeMejor = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < p; ++j){
            std::cin >> costes[i][j];
            costeMejor += costes[i][j];
        }
    }
    
    bool haySol = false;
    if(n == 0 || p == 0)
        std::cout << 0 << "\n";
    else{
        supermercado(sol, 0, n, p, costes, marcas, 0, costeMejor, haySol);
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
