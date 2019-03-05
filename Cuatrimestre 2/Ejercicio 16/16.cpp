//Ejercicio 16
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Persona.h"
#include "Lista_Extendida.h"


bool resuelveCaso() {
	int n, min, max;
	std::cin >> n >> min >> max;

	if (n == 0 && min == 0 && max == 0) return false;

	ListaExtendida<Persona> lista;

	Persona aux;
	for (int i = 0; i < n; ++i) {
		std::cin >> aux;
		lista.push_back(aux);
	}

	lista.remove_if([min, max](Persona p) { return (p.getEdad() >= min && p.getEdad() <= max); });

	std::cout << lista << "---\n";

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
