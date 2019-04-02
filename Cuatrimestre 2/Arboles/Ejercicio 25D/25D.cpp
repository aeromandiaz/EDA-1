//Ejercicio 25D
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include "bintree_eda.h"


bool esSimetrico(const bintree<char> &a1, const bintree<char> &a2) {
	if (a1.empty() && a2.empty()) return true;
	else if (a1.empty() && !a2.empty()) return false;
	else if (!a1.empty() && a2.empty()) return false;
	else {
		bool simIz, simDr;
		simIz = esSimetrico(a1.left(), a2.right());
		simDr = esSimetrico(a1.right(), a2.left());

		return simIz && simDr;
	}
}

bool esSimetrico(const bintree<char> &arbol) {
	if (arbol.empty()) return true;
	return esSimetrico(arbol.left(), arbol.right());
}

void resuelveCaso() {

	char fin = '.';
	bintree<char> arbol = leerArbol(fin);

	if (esSimetrico(arbol)) std::cout << "SI\n";
	else std::cout << "NO\n";

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