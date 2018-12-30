//Ejercicio 45
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

struct tSol {
    int sumaMejor;
    int diaIni;
    int longitud;
};

tSol resolver(std::vector<int> const& v) {
    
    tSol sol = {0, 0, 0};
    
    int sumaActual = 0, diaIniActual = 0, longitudActual = 0;
    
    for (int i = 0; i < v.size(); ++i) {
        sumaActual += v[i];
        
        if(sumaActual <= 0) {
            sumaActual = 0;
            diaIniActual = i + 1;
        } else {
            longitudActual = i;
            if(sumaActual >= sol.sumaMejor) {
                if(sumaActual > sol.sumaMejor) {
                    sol.sumaMejor = sumaActual;
                    sol.longitud = i;
                    sol.diaIni = diaIniActual;
                } else {
                    if(longitudActual - diaIniActual < sol.longitud - sol.diaIni) {
                        sol.diaIni = diaIniActual;
                        sol.longitud = longitudActual;
                    }
                }
            }
        }
    }
    
    return sol;
}

bool resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    if (!std::cin) return false;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    tSol sol = resolver(v);
    std::cout << sol.sumaMejor << " " << sol.diaIni << " " << (sol.longitud + 1 - sol.diaIni) << "\n";
    
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
