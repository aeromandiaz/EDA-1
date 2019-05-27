#ifndef autoescuela_h
#define autoescuela_h

#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <stdexcept>

using profesor = typename std::string;
using alumno = typename std::string;

struct tInfo {
    int puntuacion;
    profesor p;
    std::set<alumno>::const_iterator itAl;
};

class Autoescuela {
    std::unordered_map<alumno, tInfo> alumnos;
    std::unordered_map<profesor, std::set<alumno>> profesores;
    
public:
    
    Autoescuela() {}
    
    void alta(const alumno &A, const profesor &P) { //O(1)
        auto it = alumnos.find(A);
        if (it == alumnos.cend()) {
            const auto it2 = profesores[P].insert(A);
            alumnos[A] = {0, P, it2.first};
        } else {
            profesores[it->second.p].erase(it->second.itAl);
            it->second.p = P;
            const auto it2 = profesores[P].insert(A);
            it->second.itAl = it2.first;
        }
    }
    
    bool es_alumno(const alumno &A, const profesor &P) const { //O(1)
        return (alumnos.count(A) == 1 && alumnos.at(A).p == P);
    }
    
    int puntuacion(const alumno &A) const { //O(1)
        auto it = alumnos.find(A);
        if (it == alumnos.cend())
            throw std::domain_error("El alumno " + A + " no esta matriculado");
        return it->second.puntuacion;
    }
    
    void actualizar(const alumno &A, const int &N) { //O(1)
        auto it = alumnos.find(A);
        if (it == alumnos.cend())
            throw std::domain_error("El alumno " + A + " no esta matriculado");
        it->second.puntuacion += N;
    }
    
    std::vector<alumno> examen(const profesor &P, const int &N) const { //O(1)
        std::vector<alumno> res;
        auto it1 = profesores.find(P);
        if (it1 == profesores.cend())
            return res;
        auto it2 = it1->second.cbegin();
        
        while (it2 != it1->second.cend()) {
            if (alumnos.find(*it2)->second.puntuacion >= N)
                res.push_back(*it2);
            it2++;
        }
        return res;
    }
    
    void aprobar(const alumno &A) { //O(1)
        auto it = alumnos.find(A);
        if (it == alumnos.cend())
            throw std::domain_error("El alumno " + A + " no esta matriculado");
        profesores[it->second.p].erase(it->second.itAl);
        alumnos.erase(it);
    }
    
};

#endif // autoescuela_h
