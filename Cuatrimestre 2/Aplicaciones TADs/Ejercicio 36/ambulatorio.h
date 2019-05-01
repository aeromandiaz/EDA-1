#ifndef ambulatorio_h
#define ambulatorio_h

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <vector>
#include <stdexcept>
#include "fecha.h"

using medico = std::string;
using paciente = std::string;

struct tCita {
    paciente p;
    Fecha f;
};

class ambulatorio {
    std::unordered_map <medico, std::map<Fecha, paciente>> mapa;
    
public:
    void nuevoMedico(medico m) {
        mapa.insert({ m, {} }).second;
    }
    
    void pideConsulta(const paciente &p, const medico &m, const Fecha &f) {
        auto itm = mapa.find(m);
        if (itm == mapa.cend())
            throw std::domain_error("Medico no existente");
        else {
            auto itf = mapa[m].find(f);
            if (itf != mapa[m].cend())
                throw std::domain_error("Fecha ocupada");
            
            else mapa[m][f] = p;
        }
    }
    
    paciente siguientePaciente(const medico &m) {
        auto itm = mapa.find(m);
        if (itm == mapa.cend())
            throw std::domain_error("Medico no existente");
        else {
            if (mapa[m].empty())
                throw std::domain_error("No hay pacientes");
            else return mapa[m].begin()->second;
        }
    }
    
    void atiendeConsulta(const medico &m) {
        auto itm = mapa.find(m);
        if (itm == mapa.end())
            throw std::domain_error("Medico no existente");
        else {
            if (mapa[m].empty())
                throw std::domain_error("No hay pacientes");
            else
                mapa[m].erase(mapa[m].begin());
        }
    }
    
    std::vector<tCita> listaPacientes(const medico &m, int d) {
        std::vector<tCita> lista;
        tCita elemento;
        auto itm = mapa.find(m);
        if (itm == mapa.cend())
            throw std::domain_error("Medico no existente");
        else{
            if (mapa[m].empty())
                return lista;
            else {
                for (auto &p : mapa[m]){
                    if (p.first.getDia() == d){
                        elemento = { p.second, p.first };
                        lista.push_back(elemento);
                    }
                }
                return lista;
            }
        }
        return lista;
    }
};


#endif
