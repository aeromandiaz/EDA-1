#ifndef Amazon_h
#define Amazon_h

#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <list>
#include <iterator>
#include <stdexcept>
#include <map>

using libro = std::string;

const int TOP = 10;

struct tEst{
    int vendidos = 0;
    int unidades = 0;
};

class Amazon {
private:
    std::unordered_map<libro, tEst>ejemplares;
    std::map<int, std::list<libro>>tablaVentas;
    std::unordered_map<libro, std::list<libro>::const_iterator>iteradores;
    
public:
    void nuevoLibro(int n, const libro &x) {
        ejemplares[x].unidades += n;
    }
    
    void comprar(const libro &x){
        auto itL = ejemplares.find(x);
        
        if (itL == ejemplares.cend())
            throw std::invalid_argument("Libro no existente");
        else{
            if (itL->second.unidades == 0)
                throw std::out_of_range("No hay ejemplares");
            else {
                if (itL->second.vendidos == 0) {
                    tablaVentas[1].push_front(x);
                    iteradores[x] = tablaVentas[1].begin();
                }
                else {
                    tablaVentas[itL->second.vendidos].erase(iteradores[x]);
                    tablaVentas[itL->second.vendidos + 1].push_front(x);
                    iteradores[x] = tablaVentas[itL->second.vendidos + 1].begin();
                }
                itL->second.unidades--;
                itL->second.vendidos++;
            }
        }
    }
    
    bool estaLibro(const libro &x) {
        auto itL = ejemplares.find(x);
        if (itL == ejemplares.cend())
            return false;
        else
            return true;
    }
    
    void elimLibro(const libro &x) {
        auto itL = ejemplares.find(x);
        if (itL != ejemplares.end()){
            if (itL->second.vendidos > 0){
                tablaVentas[itL->second.vendidos].erase(iteradores[x]);
                iteradores.erase(x);
            }
            ejemplares.erase(x);
            
        }
    }
    
    int numEjemplares(const libro &x) {
        auto itL = ejemplares.find(x);
        if (itL == ejemplares.cend())
            throw std::invalid_argument("Libro no existente");
        else
            return itL->second.unidades;
    }
    
    
    std::list<libro> top10(){
        std::list<libro> top10;
        int n = 0;
        auto it = tablaVentas.rbegin();
        while (it != tablaVentas.rend() && n < TOP) {
            auto itCola = it->second.begin();
            while (n < TOP && itCola != it->second.cend()) {
                top10.push_back(*itCola);
                itCola++;
                ++n;
            }
            it++;
        }
        return top10;
    }
    
};


#endif
