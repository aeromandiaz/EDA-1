#include <iostream>
#include <fstream>
#include <vector>

bool esValida(const std::vector<int> &sol, std::vector<int> &marcas, int k, int n) {
    
    if(sol[k] > sol[k - 1] + 1) return false;
    if(sol[k] < sol[k - 1]) return false;
    if(k >= sol.size() / 2) { //Si estamos a mas de la mitad del vector solución
        //Si el elemento actual es distinto anterior, comprobamos que el numero de veces que aparece el elemento anterior aparece igual o más veces que el anterior del anterior.
        if(sol[k-1] != sol[k] && k - 2 >= 0 && marcas[sol[k - 2] - 1] > marcas[sol[k - 1] - 1]) return false;
    }
    
    return true;
}

bool esSolucion(const std::vector<int> &sol, std::vector<int> &marcas, int i) {
    
    if (i != 0 && (marcas[i-1] > marcas[i])) return false; //Comprobamos que el último elemento aparece el mismo número de veces o más que el anterior (siempre y cuando el vector no sea exclusivamente de 1's)
        
    return true;
}

void va(std::vector<int> &sol, std::vector<int> &marcas, int k, int n) {
    
    for (int i = 1; i <= n; ++i) {
        sol[k] = i;
        ++marcas[i-1];
        if(esValida(sol, marcas, k, n)) {
            if (k + 1 == n) {
                if (esSolucion(sol, marcas, i-1)) {
                    for (int z = 0; z < n; ++z) {
                        std::cout << sol[z];
                        if (z + 1 < n)
                            std::cout << " ";
                    }
                    std::cout << "\n";
                }
            } else
                va(sol, marcas, k + 1, n);
        }
        --marcas[i-1];
    }
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if (n == 0) return false;
    
    std::vector<int> sol(n, 0), marcas(n, 0);
    sol[0] = 1;
    ++marcas[0];

    va(sol, marcas, 1, n);
    
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
