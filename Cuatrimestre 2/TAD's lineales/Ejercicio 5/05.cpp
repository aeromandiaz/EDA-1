//Ejercicio 05
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include "set.h"


bool resuelveCaso() {

	char tipo;
	
	std::cin >> tipo;

	if (!std::cin) return false;

	if (tipo == 'N') {
		int N;
		std::cin >> N;
		set<int> conjunto(N);

		int aux;
		std::cin >> aux;
		while (aux != -1) {
			conjunto.insert(aux);
			std::cin >> aux;
		}

		std::cout << conjunto << "\n";
	}
	else {
		int N;
		std::cin >> N;
		set<std::string> conjunto(N);

		std::string aux;
		std::cin >> aux;
		while (aux != "FIN") {
			conjunto.insert(aux);
			std::cin >> aux;
		}

		std::cout << conjunto << "\n";
	}

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