//Ejercicio 33
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <vector>


struct tProblema{
    int tiempo = 0;
    int intentos = 0;
    bool resuelto = false;
    std::string veredicto;
};

struct tSol {
    std::string equipo;
    int resueltos;
    int tiempoTotal;
};

using iMap = std::unordered_map<std::string, std::unordered_map<std::string, tProblema>>;

bool operator> (tSol a, tSol b){
    if (a.resueltos > b.resueltos) return true;
    else if (a.resueltos == b.resueltos && a.tiempoTotal < b.tiempoTotal) return true;
    else if (a.resueltos == b.resueltos && a.tiempoTotal == b.tiempoTotal && a.equipo < b.equipo) return true;
    else return false;
}

void resuelveCaso() {
    
    std::string equipo, problema;
    iMap mapaInscritos;
    std::unordered_map<std::string, tSol> mapaResueltos;
    std::cin >> equipo;

    while (equipo != "FIN"){
        tProblema estProblema;
        std::cin >> problema;
        std::cin.ignore();
        std::cin >> estProblema.tiempo >> estProblema.veredicto;
        
        if (estProblema.veredicto != "AC")
            estProblema.intentos = 1;
    
        if (mapaInscritos.count(equipo) == 0) {
            mapaResueltos[equipo] = { equipo, 0, 0 };
            mapaInscritos[equipo].insert({problema, estProblema});
        }
        else if (mapaInscritos.count(equipo) == 1 && mapaInscritos.at(equipo).count(problema) == 1) {
            if (estProblema.veredicto != "AC" && !mapaInscritos[equipo][problema].resuelto)
                mapaInscritos[equipo][problema].intentos++;
        } else
            mapaInscritos[equipo].insert({problema, estProblema});
        
        if (estProblema.veredicto == "AC" && !mapaInscritos[equipo][problema].resuelto) {
            mapaResueltos[equipo].resueltos++;
            mapaInscritos[equipo][problema].resuelto = true;
            mapaResueltos[equipo].tiempoTotal += estProblema.tiempo + (mapaInscritos[equipo][problema].intentos * 20);
        }
        
        std::cin.ignore();
        std::cin >> equipo;
    }
    
    std::vector<tSol>sol;
    
    for (auto &m : mapaResueltos)
        sol.push_back({m.first, m.second.resueltos, m.second.tiempoTotal});
    
    std::sort(sol.begin(), sol.end(), std::greater<tSol>());
    
    for (auto &t : sol)
        std::cout << t.equipo << " " << t.resueltos << " " <<  t.tiempoTotal << "\n";
    
    std::cout << "----\n";
    
}

int main() {
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    int n = 0;
    std::cin >> n;
    for(int i = 0; i < n; ++i) resuelveCaso();
     
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
