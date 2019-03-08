//Ejercicio 08_A
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "ListaDuplica_A.h"


bool resuelveCaso() {

	int n, elimina;
	std::cin >> n;

	if (!std::cin) return false;

	ListaDuplica<int> lista, listaFinal;

	while (n != 0) {
		lista.push(n);
		std::cin >> n;
	}

	std::cin >> n;
	while (n != 0) {
		listaFinal.push(n);
		std::cin >> n;
	}

	std::cin >> elimina;

	lista.duplicar();

	std::cout << lista.size() << "\n";
	std::cout << lista << '\n';

	lista.anhadeFinal(listaFinal);
	lista.eliminaIni(elimina);

	std::cout << lista.size() << "\n";
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

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

}
