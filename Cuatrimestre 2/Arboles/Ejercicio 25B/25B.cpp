//Ejercicio 25B
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "bintree_eda.h"

struct tSol {
	int nodos;
	bool valido;
};

tSol resolver(const bintree<char> &arbol) {
	if (arbol.empty()) 
		return { 0 , true };
	else if (arbol.left().empty() && arbol.right().empty())
		return { 1, true };
	else {
		tSol sol;
		tSol iz = resolver(arbol.left());
		tSol dr = resolver(arbol.right());

		sol.nodos = iz.nodos + dr.nodos + 1;
		sol.valido = iz.valido && dr.valido && dr.nodos < iz.nodos;

		return sol;
	}
}


bool resuelveCaso() {

	bintree<char> arbol = leerArbol('.');

	if (resolver(arbol).valido) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
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
