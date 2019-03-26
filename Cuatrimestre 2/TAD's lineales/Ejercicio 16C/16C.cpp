//Ejercicio 16C
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include "Horas.h"
#include "ListaBorraPar.h"


bool resuelveCaso() {

	ListaBorraPar<Horas> lista;
	Horas tmp;

	int n = 0;
	std::cin >> n;

	if (n == 0) return false;

	for (int i = 0; i < n; ++i) {
		std::cin >> tmp;
		lista.push(tmp);
	}

	lista.borrar();

	std::cout << lista << '\n';
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