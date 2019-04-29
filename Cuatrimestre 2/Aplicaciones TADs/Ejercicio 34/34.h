#ifndef carnet_h
#define carnet_h

#include <unordered_map>
#include <stdexcept>
#include <string>
#include <vector>

class carnet_puntos {
	const int MAXPUNTOS = 15;
	std::unordered_map<std::string, int> map;
	std::vector<int> cuantosConPuntos;

public:

	carnet_puntos(): cuantosConPuntos(MAXPUNTOS + 1, 0) {}

	void nuevo(const std::string &dni) {
		if (map.count(dni) == 1)
			throw std::domain_error("Conductor duplicado");
		map[dni] = MAXPUNTOS;
		cuantosConPuntos[MAXPUNTOS]++;
	}

	void quitar(const std::string &dni, int puntos) {
		if (map.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");
		if (map.at(dni) == 0)
			map[dni] = 0;
		else if (map.at(dni) < puntos) {
			cuantosConPuntos[map[dni]]--;
			map[dni] = 0;
			cuantosConPuntos[0]++;
		} 
		else {
			cuantosConPuntos[map[dni]]--;
			map[dni] -= puntos;
			cuantosConPuntos[map[dni]]++;
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
		
		return cuantosConPuntos[puntos];
	}
};

#endif