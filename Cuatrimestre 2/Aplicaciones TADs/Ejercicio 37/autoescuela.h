#ifndef autoescuela_h
#define autoescuela_h

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stdexcept>

using alumno = std::string;
using profesor = std::string;

class autoescuela {
    std::unordered_map<alumno, int>tablaPuntuacion;
    std::unordered_map<alumno, profesor>tablaAlumnos;
    std::unordered_map<profesor, std::vector<alumno>>tablaProfesores;
    
public:
    autoescuela() {};
    
    void alta(const alumno &a, const profesor &p) {
        if (tablaPuntuacion.count(a) == 0){
            tablaPuntuacion.insert({ a, 0 });
            tablaAlumnos[a] = p;
            tablaProfesores[p].push_back(a);
        }
        else {
            profesor aux = tablaAlumnos[a];
            tablaAlumnos[a] = p;
            for (int i = 0; i < tablaProfesores[aux].size(); ++i) {
                if (tablaProfesores[aux][i] == a) {
                    tablaProfesores[aux][i] = tablaProfesores[aux][tablaProfesores[aux].size() - 1];
                    tablaProfesores[aux].pop_back();
                }
            }
            tablaProfesores[p].push_back(a);
        }
    }
    
    bool esAlumno(const alumno &a, const profesor &p) {
        if (tablaAlumnos[a] == p)
            return true;
        else
            return false;
    }
    
    int puntuacion(const alumno &a) {
        auto itA = tablaAlumnos.find(a);
        if (itA == tablaAlumnos.cend())
            throw std::domain_error("El alumno " + a + "no esta matriculado");
        else
            return tablaPuntuacion[a];
    }
    
    void actualizar(const alumno &a, int n) {
        auto itA = tablaPuntuacion.find(a);
        if (itA == tablaPuntuacion.cend())
            throw std::domain_error("El alumno " + a + "no esta matriculado");
        else
            itA->second += n;
    }
    
    std::vector<alumno> examen(const profesor &p, int n) {
        std::vector<alumno>sol;
        auto itP = tablaProfesores.find(p);
        if (itP == tablaProfesores.end()) tablaProfesores.insert({ p, {} });
        else{
            for (auto &a : itP->second){
                if (tablaPuntuacion[a] >= n)
                    sol.push_back(a);
            }
            std::sort(sol.begin(), sol.end());
        }
        return sol;
    }
    
    void aprobar(const alumno &a) {
        if (tablaAlumnos.find(a) == tablaAlumnos.end())
            throw std::domain_error("El alumno " + a + "no esta matriculado");
        tablaAlumnos.erase(a);
        tablaPuntuacion.erase(a);
        auto itP = tablaProfesores.begin();
        while (itP != tablaProfesores.end()){
            for (int i = 0; i < itP->second.size(); ++i){
                if (itP->second[i] == a){
                    itP->second[i] = itP->second[itP->second.size() - 1];
                    itP->second.pop_back();
                }
            }
            ++itP;
        }
    }
};


#endif
