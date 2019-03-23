//Ejercicio 26
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "bintree_eda.h"

struct tSol {
	int max;
	int min;
	bool valido;
};

tSol resolver(const bintree<int> &arbol) {
	if (arbol.empty()) return { -1, -1, true };
	else if (arbol.left().empty() && arbol.right().empty())
		return { arbol.root(), arbol.root(), true };
	else if (arbol.left().empty()) {
		tSol sol = resolver(arbol.right());
		if (arbol.root() < sol.min && sol.valido) sol.valido = true;
		else sol.valido = false;
		sol.min = std::min(sol.min, arbol.root());
		sol.max = std::max(sol.max, arbol.root());
		return sol;
	}
	else if (arbol.right().empty()) {
		tSol sol = resolver(arbol.left());
		if (arbol.root() > sol.max && sol.valido) sol.valido = true;
		else sol.valido = false;
		sol.min = std::min(sol.min, arbol.root());
		sol.max = std::max(sol.max, arbol.root());
		return sol;
	}
	else {
		tSol sol;
		tSol iz = resolver(arbol.left());
		tSol dr = resolver(arbol.right());
		sol.max = std::max(dr.max, iz.max);
		sol.max = std::max(sol.max, arbol.root());

		sol.min = std::min(iz.min, dr.min);
		sol.min = std::min(sol.min, arbol.root());

		if (iz.valido && dr.valido && iz.max < arbol.root() && dr.min > arbol.root()) sol.valido = true;
		else sol.valido = false;
		return sol;
	}
}


bool resuelveCaso() {

	bintree<int> arbol = leerArbol(-1);

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
