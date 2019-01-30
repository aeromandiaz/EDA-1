//Ejercicio 42
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

int resolver(std::vector<int> const& v) {
    
    int max = v[0], res = 0, ac = 1;
    
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > max) {
            res += (max * ac);
            max = v[i];
            ac = 1;
        } else if (v[i] == max)
            ++ac;
        else res += v[i];
    }
    
    return res;
}

void resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    std::vector<int>v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    
    std::cout << resolver(v) << "\n";
    
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

    for(int i = 0;i < n; ++i)
        resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}
