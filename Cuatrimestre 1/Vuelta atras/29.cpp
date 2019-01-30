//Ejercicio 29
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

using tVector = std::vector<int>;

bool esValida(const tVector &sol, const int &k, const tVector &cantAb, const tVector &est, const tVector &marcas, const int &i) {
    
    if (k > 0 && sol[k - 1] == sol [k]) return false;
    if (k > 0 && marcas[i] + 1 > (2 + (k / 3))) return false;
    if (cantAb[i] < est[k] ) return false;
    if (k + 1 == est.size() && sol[0] == sol[k]) return false;
    
    return true;
}

void vueltaAtras(tVector &aux, const tVector &cantAb, const tVector &est, int k, int &sol, tVector &marcas, bool &haySol){
    for (int i = 0; i < cantAb.size(); ++i) {
        aux[k] = i;
        if (esValida(aux, k, cantAb, est, marcas, i)) {
            if (k + 1 == est.size()) { //Es solución
                haySol = true;
                ++sol;
            } else {
                marcas[i]++;
                vueltaAtras(aux, cantAb, est, k + 1, sol, marcas, haySol);
                marcas[i]--;
            }
        }
    }
}


bool resuelveCaso() {
    int n, a;
    std::cin >> n >> a;
    
    if(n == 0 && a == 0) return false;
    
    bool haySol = false;
    int sol = 0;
    tVector est(n), cantidad(a), aux(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> est[i];
    for (int i = 0; i < a; ++i)
        std::cin >> cantidad[i];
    
    tVector marcas(a, 0);
    
    vueltaAtras(aux, cantidad, est, 0, sol, marcas, haySol);
    
    if (!haySol) std::cout << "Lo puedes comprar\n";
    else std::cout << sol << "\n";
    
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
