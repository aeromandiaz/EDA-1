//Ejercicio 09
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "InvierteListaDoble.h"


bool resuelveCaso() {

	InvierteLista<int> lista1;
	int tmp;

	std::cin >> tmp;

	if (!std::cin) return false;

	while (tmp != 0) {
		lista1.push_back(tmp);
		std::cin >> tmp;
	}

	lista1.invierte();

	std::cout << lista1 << '\n';

	return true;
}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while(resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

}
