//
//  Pelicula.h
//  ProblemasEDA
//
//  Created by Mauri on 30/01/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef Pelicula_h
#define Pelicula_h

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Horas.h"

class Pelicula {
    Horas horaInicio, duracion;
    std::string titulo;
    
public:
    Pelicula(): titulo(""), horaInicio(Horas()), duracion(Horas()) {}
    Pelicula(std::string nombre, Horas ini, Horas fin): titulo(nombre), horaInicio(ini), duracion(fin) {}
    
    bool operator<(const Pelicula &p) const {
        if ((horaInicio + duracion) < (p.getIni() + p.getDuracion())) return true;
        else if ((p.getIni() + p.getDuracion()) < (horaInicio + duracion)) return false;
        else if (titulo < p.getTitulo()) return true;
        else return false;
    }
    
    Horas getIni() const { return horaInicio; }
    Horas getDuracion() const { return duracion; }
    Horas getFin() const { return horaInicio + duracion; }
    std::string getTitulo() const { return titulo; }
    
};

inline std::ostream& operator <<(std::ostream &out , Pelicula const& p) {
    
    out << p.getFin() << " " << p.getTitulo();
    
    return out;
}

inline std::istream& operator >>(std:: istream &in , Pelicula &p) {
    
    Horas ini, dur;
    std::string tit;
    
    in >> ini >> dur;
    std::getline(in, tit);
    
    p = Pelicula(tit, ini, dur);
    
    return in;
}

#endif /* Pelicula_h */
