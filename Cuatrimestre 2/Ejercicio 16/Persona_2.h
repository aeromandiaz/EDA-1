//
//  Persona.h
//  ProblemasEDA
//
//  Created by Mauri on 01/03/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef Persona_h
#define Persona_h

#include <iostream>
#include <string>

class Persona {
    int edad;
    std::string nombre;
    
public:
    Persona() : edad(0), nombre("") {}
    Persona(int e, const std::string &n) : edad(e), nombre(n) {}
    
    int getEdad() const { return edad;    }
    
    std::string getNombre() const { return nombre; }
    
};


inline std::ostream& operator <<(std::ostream &out, Persona const& p) {
    
    out << p.getNombre();
    
    return out;
}


inline std::istream& operator >>(std::istream &in, Persona &p) {
    
    int edad;
    std::string n;
    
    in >> edad;
    in.ignore();
    std::getline(in, n);
    
    p = Persona(edad, n);
    
    return in;
}

#endif /* Persona_h */
