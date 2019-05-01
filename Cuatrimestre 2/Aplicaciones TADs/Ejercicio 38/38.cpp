//Ejercicio 38
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include "iPod.h"


bool resuelveCaso() {
    
    iPod miPod;
    cancion s;
    artista a;
    int d;
    
    std::string orden;
    std::cin >> orden;
    
    if (!std::cin) return false;
    
    while (orden != "FIN") {
        try {
            if (orden == "addSong") {
                std::cin >> s >> a >> d;
                miPod.addSong(s, a, d);
            }
            else if (orden == "addToPlaylist") {
                std::cin >> s;
                miPod.addToPlayList(s);
            }
            else if (orden == "play") {
                cancion  aux = miPod.play();
                if (!aux.empty()) std::cout << "Sonando " << aux << "\n";
                else std::cout << "No hay canciones en la lista\n";
                
            }
            else if (orden == "deleteSong") {
                std::cin >> s;
                miPod.deleteSong(s);
            }
            else if (orden == "totalTime")
                std::cout << "Tiempo total " << miPod.totalTime() << "\n";
            else if (orden == "recent") {
                std::cin >> d;
                std::list<cancion> lista = miPod.recent(d);
                if (!lista.empty()){
                    std::cout << "Las " << lista.size() << " mas recientes\n";
                    for (auto const & c : lista)
                        std::cout << "    " << c << "\n";
                }
                else std::cout << "No hay canciones recientes\n";
            }
            else if (orden == "current")
                miPod.current();
        }
        catch (std::domain_error e) {
            std::cout << "ERROR "  << e.what() << "\n";
        }
        std::cin >> orden;
    }
    std::cout << "----\n";
    
    return true;
}

int main() {
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    while (resuelveCaso());
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
