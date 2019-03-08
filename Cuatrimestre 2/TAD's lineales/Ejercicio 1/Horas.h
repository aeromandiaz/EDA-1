//
//  Horas.h
//  ProblemasEDA
//
//  Created by Mauri on 30/01/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//


#ifndef Horas_h
#define Horas_h

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>

class Horas {
    int hora, minutos, segundos;
    
    bool proximaHora(const Horas &horaLlegada, const Horas &horarioEstacion) const {
        return horarioEstacion < horaLlegada;
    }
    
public:
    Horas() : hora(0), minutos(0), segundos(0) {}
    Horas(int h, int m, int s) : hora(h), minutos(m), segundos(s) {
        if (s < 0 || s > 59)  throw  std::invalid_argument("ERROR");
        else if (m < 0 || m > 59)  throw  std::invalid_argument("ERROR");
        else if (h < 0 || h > 23)  throw  std::invalid_argument("ERROR");
    }
    
    bool operator<(const Horas &h) const {
        if (hora < h.hora) return  true;
        else if (hora > h.hora) return  false;
        else if (minutos < h.minutos) return  true;
        else if (minutos > h.minutos) return  false;
        else if (segundos < h.segundos) return  true;
        else  return  false;
    }
    
    int getHora() const { return hora; }
    int getMinutos() const { return minutos; }
    int getSegundos() const { return segundos; }
    
    bool proximoTren(const Horas &h, Horas &horaPartida) const {
        
        if (!proximaHora(h, *this)) {
            horaPartida = *this;
            return true;
        }
        
        return false;
    }
    
};

inline std::ostream& operator <<(std::ostream &out, Horas const& h) {
    
    out << std::setfill('0') << std::setw(2) << h.getHora() << ":" <<
    std::setfill('0') << std::setw(2) << h.getMinutos() << ":" <<
    std::setfill('0') << std::setw(2) << h.getSegundos();
    
    return out;
}

inline std::istream& operator >>(std::istream &in, Horas &hora) {
    int h, m, s;
    char aux;
    
    in >> h >> aux >> m >> aux >> s;
    
    hora = Horas(h, m, s);
    
    return in;
}

#endif /* Horas_h */
