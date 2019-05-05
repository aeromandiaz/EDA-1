//Ejercicio 35
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include "35.h"


bool resuelveCaso() {
    
	std::string orden, dni;
	int punt;
	std::cin >> orden;
	if (!std::cin)
		return false;

	carnet_puntos dgt;

	while (orden != "FIN") {
		try {
			if (orden == "nuevo") {
				std::cin >> dni;
				dgt.nuevo(dni);
			}
			else if (orden == "quitar") {
				std::cin >> dni >> punt;
				dgt.quitar(dni, punt);
			}
			else if (orden == "recuperar") {
				std::cin >> dni >> punt;
				dgt.recuperar(dni, punt);
			}
			else if (orden == "consultar") {
				std::cin >> dni;
				punt = dgt.consultar(dni);
				std::cout << "Puntos de " << dni << ": " << punt << '\n';
			}
			else if (orden == "cuantos_con_puntos") {
				std::cin >> punt;
				int cuantos = dgt.cuantos_con_puntos(punt);
				std::cout << "Con " << punt << " puntos hay " << cuantos << '\n';
			}
			else if (orden == "lista_por_puntos") {
				std::cin >> punt;
				auto const& lista = dgt.lista_por_puntos(punt);
				std::cout << "Tienen " << punt << " puntos:";
				for (auto const& dni : lista)
					std::cout << ' ' << dni;
				std::cout << '\n';
			}
			else
				std::cout << "OPERACION DESCONOCIDA\n";
		}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << '\n';
		}
		std::cin >> orden;
	}
	std::cout << "---\n";
	return true;
}

int main() {
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    while (resuelveCaso());
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
