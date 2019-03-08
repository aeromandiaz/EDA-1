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
    out << std::setfill('0') << std::setw(2) << h.getHora() << ":" <<
    std::setfill('0') << std::setw(2) << h.getMinutos() << ":" <<
    std::setfill('0') << std::setw(2) << h.getSegundos();
    
    return out;
}

inline std::istream& operator >>(std:: istream &in , Horas &hora) {
    int h, m, s;
    char aux;
    
    in >> h >> aux >> m >> aux >> s;
    
    hora = Horas(h, m, s);
    
    return in;
}

#endif /* Horas_h */
