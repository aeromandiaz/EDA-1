//Ejercicio 25
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

bool esValida(const std::vector<int> &marcas, const int &seguidas, const int &i, const int &k, const int &n, const int &maxConsumos, const int &consumoAcumulado){
    
    if (consumoAcumulado > maxConsumos) return false;
    if (seguidas > 2) return false;
    if (k + 1 - marcas[i] < (k + 1) / 2) return false;
    
    return true;
}


void vueltaAtras(std::vector<int> &aux, int k, const std::vector<int> &consumos, int seguidas, const int &n, int &sumaSol, const int &colores, std::vector<int> &marcas, const int &maxConsumo, int consumoAc){
    for (int i = 0; i < colores; ++i) {
        ++marcas[i];
        aux[k] = i;
        consumoAc += consumos[i];
        int temp = seguidas;
        if (k > 0 && aux[k] != aux[k-1])
            seguidas = 1;
        else
            ++seguidas;
        if (esValida(marcas, seguidas, i, k, n, maxConsumo, consumoAc)) {
            if (k == n - 1) { //Es solución
                ++sumaSol;
            } else {
                vueltaAtras(aux, k + 1, consumos, seguidas, n, sumaSol, colores, marcas, maxConsumo, consumoAc);
            }
        }
       seguidas = temp;
        --marcas[i];
        consumoAc -= consumos[i];
    }
}


bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if(!std::cin) return false;
    
    int sol = 0, seguidas = 0, colores, maxConsumo;
    
    std::cin >> colores >> maxConsumo;
    
    std::vector<int> consumos(colores), v(n);
    std::vector<int> marcas(colores, 0);
    
    for (int i = 0 ; i < colores; ++i)
        std::cin >> consumos[i];
    
    vueltaAtras(v, 0, consumos, seguidas, n, sol, colores, marcas, maxConsumo, 0);
    
    std::cout << sol << "\n";
    
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
