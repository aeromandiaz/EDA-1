//Ejercicio 25C
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_25C.h"


void resuelveCaso() {

	std::string fin = "...";
	bintreePlus arbol = leerArbolPlus(fin);

	tSol sol = arbol.dragones();

	std::cout << sol.nombre << " " << sol.numDragones << "\n";

}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

}