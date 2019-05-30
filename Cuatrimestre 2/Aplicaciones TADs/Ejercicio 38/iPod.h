#ifndef iPod_h
#define iPod_h

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <iterator>
#include <stdexcept>

using cancion = typename std::string;
using artista = typename std::string;

struct tInfo {
    artista a;
    int duracion;
    std::list<cancion>::const_iterator itListaReproduccion;
    std::list<cancion>::const_iterator itListaReproducidas;
};

class iPod {
    std::unordered_map<cancion, tInfo> listaCanciones;
    std::list<cancion> listaReproduccion;
    std::list<cancion> listaReproducidas;
    int total = 0;
    
public:
    void addSong(const cancion &S, const artista &A, const int D) { //O(1)
        const auto it = listaCanciones.find(S);
        if (it != listaCanciones.cend())
            throw std::domain_error("addSong");
        else
            listaCanciones.insert({S, {A, D, listaReproduccion.cend(), listaReproducidas.cend()}});
    }
    
    void addToPlaylist(const cancion &S) { //O(1)
        const auto it = listaCanciones.find(S);
        if (it == listaCanciones.cend())
            throw std::domain_error("addToPlaylist");
        else if (it->second.itListaReproduccion == listaReproduccion.cend()) {
            listaReproduccion.push_back(S);
            auto tmp = listaReproduccion.cend();
            tmp--;
            it->second.itListaReproduccion = tmp;
            total += it->second.duracion;
        }
    }
    
    cancion current() const { //O(1)
        if (listaReproduccion.empty())
            throw std::domain_error("current");
        return listaReproduccion.front();
    }
    
    void play() { //O(1)
        if (!listaReproduccion.empty()) {
            std::cout << "Sonando " << current() << "\n";
            listaReproducidas.push_back(current());
            auto it = listaCanciones.find(current());
            it->second.itListaReproduccion = listaReproduccion.cend();
            if (it->second.itListaReproducidas != listaReproducidas.cend())
                listaReproducidas.erase(it->second.itListaReproducidas);
            auto itTmp = listaReproducidas.cend();
            itTmp--;
            it->second.itListaReproducidas = itTmp;
            listaReproduccion.pop_front();
            total -= it->second.duracion;
        }
        else
            std::cout << "No hay canciones en la lista\n";
    }
    
    int totalTime() const { //O(1)
        return total;
    }
    
    std::list<cancion> recent(int N) const { //O(n)
        std::list<cancion> resultado;
        
        auto it = listaReproducidas.crbegin();
        
        for (int i = 0; i < N && it != listaReproducidas.crend(); ++i) {
            resultado.push_back(*it);
            ++it;
        }
        return resultado;
    }
    
    void deleteSong(const cancion &S) { //O(1)
        const auto it = listaCanciones.find(S);
        if (it != listaCanciones.cend()) {
            if (it->second.itListaReproduccion != listaReproduccion.cend()) {
                total -= it->second.duracion;
                listaReproduccion.erase(it->second.itListaReproduccion);
            }
            if (it->second.itListaReproducidas != listaReproducidas.cend())
                listaReproducidas.erase(it->second.itListaReproducidas);
            listaCanciones.erase(it);
        }
    }
    
};

#endif // iPod_h
