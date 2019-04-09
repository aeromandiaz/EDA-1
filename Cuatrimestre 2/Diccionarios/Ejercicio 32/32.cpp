//Ejercicio 32
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <vector>

struct tSol{
    std::string deporte;
    int valor;
};

bool operator> (tSol a, tSol b){
    if (a.valor > b.valor) return true;
    else if (a.valor == b.valor && a.deporte < b.deporte) return true;
    else return false;
}

bool resuelveCaso() {
    
    std::string palabra;
    std::string alumno;
    std::string deporte;
    std::unordered_map<std::string, int>mapaInscritos;
    std::unordered_map<std::string, std::string>mapaAlumnos;
    std::cin >> palabra;
    
    if (!std::cin) return false;
    
    while (palabra != "_FIN_"){
        if (palabra[0] >= 'A' && palabra[0] <= 'Z') {
            deporte = palabra;
            mapaInscritos[palabra] = 0;
        }
        else {
            if (mapaAlumnos.count(palabra) == 0) {
                mapaAlumnos[palabra] = deporte;
                mapaInscritos[deporte]++;
            }
            else if (mapaAlumnos.count(palabra) == 1 && mapaAlumnos[palabra] != "sinDeporte") {
                std::string borrar;
                borrar = mapaAlumnos[palabra];
                if (borrar != deporte) {
                    mapaInscritos[borrar]--;
                    mapaAlumnos[palabra] = "sinDeporte";
                }
            }
        }
        std::cin >> palabra;
    }
    
    std::vector<tSol>sol;
    
    for (auto &m : mapaInscritos){
        tSol elem;
        elem.deporte = m.first;
        elem.valor = m.second;
        sol.push_back(elem);
    }
    
    std::sort(sol.begin(), sol.end(), std::greater<tSol>());
    
    for (auto &t : sol)
        std::cout << t.deporte << " " << t.valor << "\n";
    
    std::cout << "***\n";
    
    return true;
}

int main() {
    
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
