//Ejercicio 40
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

struct tSol {
    int maxPartidosGanados;
    int partidosSeguidos;
    int nPartidosRachaGan;
};

tSol resolver(std::vector<int> const& v) {
    
    int maxGanados = 0, contador = 0, partidosSeguidos = 0, nPartidosRachaGan = 0, fin = -1;
    
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 0) {
            ++contador;
            if (maxGanados <= contador) {
                if (maxGanados < contador)
                    partidosSeguidos = 1;
                else
                    ++partidosSeguidos;
                maxGanados = contador;
                fin = i;
            }
        } else
            contador = 0;
    }
        
    nPartidosRachaGan = v.size() - fin - 1;
    
    return tSol {maxGanados, partidosSeguidos, nPartidosRachaGan};
}

bool resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    if (!std::cin) return false;
    
    std::vector<int> v(n);
 
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    tSol sol = resolver(v);
    
    std::cout << sol.maxPartidosGanados << " " << sol.partidosSeguidos << " " << sol.nPartidosRachaGan << "\n";
    
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
