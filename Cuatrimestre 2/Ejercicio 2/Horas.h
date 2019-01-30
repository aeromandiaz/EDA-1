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
#include <vector>
#include <stdexcept>
#include <string>

class Horas {
    int hora, minutos, segundos;
    
public:
    Horas(): hora(0), minutos(0), segundos(0) {}
    Horas(int h, int m, int s): hora(h), minutos(m), segundos(s) {
        if (s < 0 || s > 59)  throw  std:: invalid_argument("ERROR");
        else if (m < 0 || m > 59)  throw  std:: invalid_argument("ERROR");
        else if (h < 0 || h > 23)  throw  std:: invalid_argument("ERROR");
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
    
    Horas operator+ (Horas const& hor) const {
        int h, m, s;
        
        if ((hora + hor.getHora() +(minutos + hor.getMinutos() +(segundos + hor.getSegundos())/60)/60) >= 24)
            throw std::invalid_argument("ERROR! Los datos sobrepasan los valores aceptables.");
        else {
            s = (segundos + hor.getSegundos()) % 60;
            m = (((segundos + hor.getSegundos()) / 60) + minutos + hor.getMinutos()) % 60;
            h = ((((segundos + hor.getSegundos()) / 60) + minutos + hor.getMinutos()) / 60) + (hora + hor.getHora());
        }
        
        return Horas(h, m, s);
    }
    
};

inline std::ostream& operator <<(std::ostream &out , Horas const& h) {
    std::string hora, minutos, segundos;
    
    if (h.getHora() == 0) hora = "00";
    else if (h.getHora() < 10) {
        hora = "0";
        hora += std::to_string(h.getHora());
    }
    else hora = std::to_string(h.getHora());
    
    if (h.getMinutos() == 0) minutos = "00";
    else if (h.getMinutos() < 10) {
        minutos = "0";
        minutos += std::to_string(h.getMinutos());
    }
    else minutos = std::to_string(h.getMinutos());
    
    if (h.getSegundos() == 0) segundos = "00";
    else if (h.getSegundos() < 10) {
        segundos = "0";
        segundos += std::to_string(h.getSegundos());
    }
    else segundos = std::to_string(h.getSegundos());
    
    out << hora << ":" << minutos << ":" << segundos;
    return out;
}

inline std::istream& operator >>(std:: istream &in , Horas &hora) {
    int h, m, s;
    char aux;
    
    in >> h >> aux >> m >> aux >> s;
    
    Horas sol(h, m, s);
    hora = sol;
    
    return in;
}

#endif /* Horas_h */
