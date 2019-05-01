#ifndef iPod_h
#define iPod_h

#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <list>
#include <iterator>
#include <stdexcept>
#include <stack>

using artista = std::string;
using cancion = std::string;

struct tCancion{
    int duracion;
    artista cantante;
};

class iPod {
private:
    std::unordered_map<cancion, tCancion> tablaCanciones;
    
    std::unordered_map<cancion, std::list<cancion>::const_iterator>tablaIteradoresplayList;
    std::list<cancion>listaReproduccion;
    
    std::list<cancion> reproducidas;
    std::unordered_map<cancion, std::list<cancion>::const_iterator>tablaIteradoresReproducidas;
    
    int time = 0;
    
public:
    void addSong(const cancion &s, const artista &a, int d) {
        if (tablaCanciones.find(s) != tablaCanciones.cend())
            throw std::domain_error("addSong");
        else
            tablaCanciones.insert({ s, { d,a } });
    }
    
    void addToPlayList(const cancion &s){
        auto itC = tablaCanciones.find(s);
        
        if (itC == tablaCanciones.cend())
            throw std::domain_error("addToPlayList");
        else {
            auto itI = tablaIteradoresplayList.find(s);
            
            if (itI == tablaIteradoresplayList.cend()) {
                listaReproduccion.push_back(s);
                auto it = listaReproduccion.cend();
                it--;
                tablaIteradoresplayList[s] = it;
                time += tablaCanciones[s].duracion;
            }
        }
    }
    
    cancion current() {
        if (listaReproduccion.empty())
            throw std::domain_error("current");
        else
            return listaReproduccion.front();
    }
    
    cancion play() {
        cancion aux;
        
        if (!listaReproduccion.empty()) {
            aux  = listaReproduccion.front();
            listaReproduccion.pop_front();
            tablaIteradoresplayList.erase(aux);
            time -= tablaCanciones[aux].duracion;
            
            auto itR = tablaIteradoresReproducidas.find(aux);
            if (itR != tablaIteradoresReproducidas.end())
                reproducidas.erase(itR->second);
            reproducidas.push_back(aux);
            
            auto itLRP = reproducidas.end();
            itLRP--;
            tablaIteradoresReproducidas[aux] = itLRP;
        }
        return aux;
    }
    
    int totalTime() {
        if (!listaReproduccion.empty())
            return time;
        else return 0;
    }
    
    std::list<cancion> recent(int N){
        std::list<cancion>sol;
        int i = 1;
        
        if (!reproducidas.empty()) {
            
            auto itRep = reproducidas.cend();
            itRep--;
            
            while (itRep != reproducidas.cbegin() && i < N) {
                sol.push_back(*itRep);
                itRep--;
                i++;
            }
            sol.push_back(*itRep);
        }
        
        return sol;
    }
    
    void deleteSong(const cancion &s){
        auto itiPod = tablaCanciones.find(s);
        
        if (itiPod != tablaCanciones.cend()) {
            auto itLP = tablaIteradoresplayList.find(s);
            if (itLP != tablaIteradoresplayList.cend()) {
                listaReproduccion.erase(itLP->second);
                tablaIteradoresplayList.erase(s);
                time -= tablaCanciones[s].duracion;
            }
            auto itR = tablaIteradoresReproducidas.find(s);
            if (itR != tablaIteradoresReproducidas.cend()) { // Esta en la lista de reproducidas
                reproducidas.erase(itR->second);
                tablaIteradoresReproducidas.erase(s);
            }
            tablaCanciones.erase(s);
        }
    }
};


#endif
