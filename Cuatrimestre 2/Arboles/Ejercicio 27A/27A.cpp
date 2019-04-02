//Ejercicio 27A
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <vector>
#include "set_eda.h"


bool resuelveCaso() {

	int n, tmp;
	std::cin >> n;

	if (n == 0) return false;

	set<int> s;

	for (int i = 0; i < n; ++i) {
		std::cin >> tmp;
		s.insert(tmp);
	}

	int m;
	std::cin >> m;

	for (int i = 0; i < m; ++i) {
		std::cin >> tmp;
		std::pair<bool, int> sol = s.lower_bound(tmp);
		if (!sol.first) std::cout << "NO HAY\n";
		else std::cout << sol.second << "\n";
	}
	
	std::cout << "---\n";
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