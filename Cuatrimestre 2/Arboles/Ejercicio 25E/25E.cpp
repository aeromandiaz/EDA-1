//Ejercicio 25E
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

struct tSol {
	int caudal;
	int tramosNavegables;
};

tSol resuelve(const bintree<int> &arbol) {
	if (arbol.left().empty() && arbol.right().empty())
		return { 1,0 };
	if (!arbol.empty()) {
		tSol sol;
		if (!arbol.left().empty() && !arbol.right().empty()) {
			tSol iz = resuelve(arbol.left());
			tSol dr = resuelve(arbol.right());
			sol.caudal = iz.caudal + dr.caudal - arbol.root();
			sol.tramosNavegables = iz.tramosNavegables + dr.tramosNavegables;
		}
		else if (arbol.left().empty()) {
			sol = resuelve(arbol.right());
			sol.caudal = sol.caudal - arbol.root();
		}
		else if (arbol.right().empty()) {
			sol = resuelve(arbol.left());
			sol.caudal = sol.caudal - arbol.root();
		}
		if (sol.caudal < 0) sol.caudal = 0;
		if (sol.caudal >= 3) sol.tramosNavegables++;
		return sol;
	}
}


bool resuelveCaso() {

	bintree<int> arbol = leerArbol(-1);

	tSol sol = resuelve(arbol);

	if (sol.caudal >= 3 && sol.caudal > 0) std::cout << sol.tramosNavegables - 1 << "\n";
	else std::cout << sol.tramosNavegables << "\n";

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
