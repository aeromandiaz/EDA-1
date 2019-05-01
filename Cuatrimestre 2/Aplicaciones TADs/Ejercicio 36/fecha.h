#ifndef fecha_h
#define fecha_h

#include <iostream>
#include <iomanip>
#include <stdexcept>

class Fecha{
    int dia;
    int hora;
    int min;
    
public:
    Fecha(int d, int h, int m) : dia(d), hora(h), min(m) {
        if (d<1 || d > 30) throw std::domain_error("Dia no valido");
        
        else if (h<0 || h > 23) throw std::domain_error("Dia no valido");
        
        else if (m<0 || m > 59) throw std::domain_error("Dia no valido");
    }
    
    Fecha() {};
    
    ~Fecha() {};
    
    bool operator<(Fecha other) const {
        if (dia< other.dia) return true;
        else if (dia > other.dia) return false;
        else{
            if (hora< other.hora) return true;
            else if (hora > other.hora) return false;
            else{
                if (min < other.min) return true;
                else return false;
            }
        }
    }
    
    int getDia() const { return dia; }
    
    int getMin() const { return hora; }
    
    int getHora() const { return min; }
    
    void pintarHora() {
        std::cout << std::setw(2) << std::setfill('0') << hora << ":" << std::setw(2) << std::setfill('0') << min;
    }
    
};
#endif
