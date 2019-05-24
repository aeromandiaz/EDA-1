#ifndef Amazon_h
#define Amazon_h

#include <string>
#include <unordered_map>
#include <list>
#include <iterator>
#include <stdexcept>
#include <map>

using libro = typename std::string;
using vendidos = int;

struct tInfo {
    int ejemplares = 0;
    vendidos v = 0;
    std::list<libro>::const_iterator it;
};

class Amazon {
    
    const int TOP = 10;
    
    std::unordered_map<libro, tInfo> libros;
    std::map<vendidos, std::list<libro>, std::greater<vendidos>> topVentas;
    
public:
    void nuevoLibro(int n, const libro &x) { //O(1)
        libros[x].ejemplares += n;
    }
    
    void comprar(const libro &x) { //O(logn)
        const auto& it = libros.find(x);
        if (it == libros.cend())
            throw std::invalid_argument("Libro no existente");
        if (it->second.ejemplares <= 0)
            throw std::out_of_range("No hay ejemplares");
        if (it->second.v > 0)
            topVentas[it->second.v].erase(it->second.it);
        it->second.ejemplares--;
        it->second.v++;
        
        auto& itTop = topVentas[it->second.v];
        itTop.push_front(it->first);
        it->second.it = itTop.cbegin();
    }
    
    bool estaLibro(const libro &x) const{ //O(1)
        return libros.count(x) == 1;
    }
    
    void elimLibro(const libro &x) { //O(logn) si hay vendidos, sino se ha vendido ninguno O(1)
        auto it = libros.find(x);
        if (it != libros.cend()) {
            if (it->second.v > 0)
                topVentas[it->second.v].erase(it->second.it);
            libros.erase(it);
        }
    }
    
    int numEjemplares(const libro &x) const { //O(1)
        const auto& it = libros.find(x);
        if (it == libros.cend())
            throw std::invalid_argument("Libro no existente");
        return it->second.ejemplares;
    }
    
    std::list<libro> top10() const { //O(n), siendo n el top de libros a consultar (en este caso, 10)
        auto it = topVentas.cbegin();
        std::list<libro> res;
        
        for(int i = 0; i < TOP && it != topVentas.cend(); ++it) {
            for (auto itLista = it->second.cbegin(); itLista != it->second.cend() && i < TOP; ++i) {
                res.push_back(*itLista);
                itLista++;
            }
        }
        
        return res;
    }
    
};

#endif
