//Ejercicio 27
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include "bintree_eda.h"

bintree<int> reconstruirArbol(const std::vector<int> &v, const std::pair<int, int> &indices) {

	if (indices.first > indices.second) return {};
	else {
		int i = indices.first + 1;
		int ac = v[indices.first];
		while (i <= indices.second && ac > v[i]) ++i;

		bintree<int> izq = reconstruirArbol(v, { indices.first + 1,i - 1 });
		bintree<int> der = reconstruirArbol(v, { i,indices.second });

		return { izq , ac , der };
	}

}

bool resuelveCaso() {

	std::string linea;
	getline(std::cin, linea);

	if (!std::cin) return false;

	int dato;
	std::vector<int> entrada;
	std::pair<int, int> indices;
	std::stringstream ss(linea);

	while (ss >> dato)
		entrada.push_back(dato);

	bintree<int> arbol = reconstruirArbol(entrada, { 0, entrada.size() - 1 });

	auto sol = arbol.postorder();

	std::cout << sol[0];
	for (int i = 1; i < sol.size(); ++i)
		std::cout << " " << sol[i];

	std::cout << "\n";

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
