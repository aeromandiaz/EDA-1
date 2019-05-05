#ifndef carnet_h
#define carnet_h

#include <unordered_map>
#include <stdexcept>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>

class carnet_puntos {
    const int MAXPUNTOS = 15;
    std::unordered_map<std::string, int> map;
	std::unordered_map<std::string, std::list<std::string>::const_iterator> posDNI;
	std::vector<std::list<std::string>> lista;
    
public:
    
    carnet_puntos(): lista(MAXPUNTOS + 1, std::list<std::string>()) {}
    
    void nuevo(const std::string &dni) {
        if (map.count(dni) == 1)
            throw std::domain_error("Conductor duplicado");
        map[dni] = MAXPUNTOS;
		lista[MAXPUNTOS].push_front(dni);
		posDNI[dni] = lista[MAXPUNTOS].cbegin();
    }
    
    void recuperar(const std::string &dni, int puntos) {
        if (map.count(dni) == 0)
            throw std::domain_error("Conductor inexistente");
        int nuevosPuntos = std::min(map[dni] + puntos, MAXPUNTOS);
        if (nuevosPuntos != map[dni]) {
            lista[map[dni]].erase(posDNI[dni]);
            map[dni] = nuevosPuntos;
            lista[map[dni]].push_front(dni);
            posDNI[dni] = lista[map[dni]].cbegin();
        }
    }
    
    void quitar(const std::string &dni, int puntos) {
        if (map.count(dni) == 0)
            throw std::domain_error("Conductor inexistente");
        int nuevosPuntos = std::max(map[dni] - puntos, 0);
        if (nuevosPuntos != map[dni]) {
            lista[map[dni]].erase(posDNI[dni]);
            map[dni] = nuevosPuntos;
            lista[map[dni]].push_front(dni);
            posDNI[dni] = lista[map[dni]].cbegin();
        }
    }
    
    int consultar(const std::string &dni) const {
        if (map.count(dni) == 0)
            throw std::domain_error("Conductor inexistente");
        return map.at(dni);
    }
    
    int cuantos_con_puntos(int puntos) const {
        if (puntos < 0 || puntos > MAXPUNTOS)
            throw std::domain_error("Puntos no validos");
        
        return lista[puntos].size();
    }

	std::list<std::string> lista_por_puntos(int puntos) {
		if (puntos < 0 || puntos > MAXPUNTOS)
			throw std::domain_error("Puntos no validos");
		return lista[puntos];
	}


};

#endif
