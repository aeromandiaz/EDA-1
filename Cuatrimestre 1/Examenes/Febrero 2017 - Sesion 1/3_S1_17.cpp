#include <iostream>
#include <fstream>
#include <vector>

bool esValida(const int &k, const std::vector<int> &sol, const int &e, const std::vector<int> &marcas, const int &d, const int &i) {
    
    if (k == 0 && sol[k] != e) return false;
    if (k > 0 && sol[k - 1] + 1 != sol[k] && sol[k - 1] != sol[k]) return false;
    if (marcas[i] > d) return false;
    
    return true;
}

/*
 K es la posicio del vector d-divertido donde se colocarán sus elementos
 i será el elemento que se meterá en la posición k.
 */
void va(std::vector<int> &sol, std::vector<int> &marcas, const int &n, const int &d, const int &e, const int &k) {
    
    for (int i = e; i <= n + 1; ++i) {
        sol[k] = i;
        ++marcas[i];
        if (esValida(k, sol, e, marcas, d, i)) {
            if (k + 1 == n) { //Es solución
                for (int z = 0; z < n; ++z) {
                    std::cout << sol[z];
                    if (z + 1 != n)
                        std::cout << " ";
                }
                std::cout << "\n";
            }
            else
                va(sol, marcas, n, d, e, k + 1);
        }
        --marcas[i];
    }
    
}

void resuelveCaso() {
    int n, d, e;
    std::cin >> n >> d >> e;
    
    std::vector<int> sol(n);
    std::vector<int> marcas(n + 1);
    //std::vector<bool> marcasCarret(n, false);

    va(sol, marcas, n, d, e, 0);
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
    
    for (int i = 0; i < n; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
