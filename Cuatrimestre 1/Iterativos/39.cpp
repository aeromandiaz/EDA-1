//Ejercicio 39
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

struct tSol {
    int ini;
    int fin;
};

tSol resuelve(std::vector<int> const& v, const int &alien) {
    
    tSol sol = {0, -1};
   
    int ini = 0, fin = 0;

    for (int i = 0; i < v.size(); ++i) {
        if(v[i] > alien) {
            if(ini == -1) {
                fin = i;
                ini = i;
            } else
                fin = i;
            
            if(fin - ini > sol.fin - sol.ini) {
                sol.fin = fin;
                sol.ini = ini;
            }
        } else {
            fin = -1;
            ini = -1;
        }
    }
    return sol;
    
}

void resuelveCaso() {
    
    int n,t;
    std::cin >> n >> t;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    tSol sol = resuelve(v, t);
    
    std::cout << sol.ini << " " << sol.fin << "\n";
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
