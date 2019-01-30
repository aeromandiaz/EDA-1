//Ejercicio 22
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct sol {
	int jugados;
	bool presentados;
	int ronda;
};

//Coste O(n)
sol calcularPartidos(const std::vector<std::string> &v, const int &ini, const int &fin, const int &totalRondas) {

	if (ini + 2 == fin) {
		if (v[ini] != "NP" && v[ini + 1] != "NP") return{ 1, true, 0 };
		else if (v[ini] == "NP" && v[ini + 1] == "NP") return{ 0, false, 0 };
		return{ 0, true, 0 };
	}

	int m = (ini + fin - 1) / 2;
	sol iz, dr, resultado;

	iz = calcularPartidos(v, ini, m + 1, totalRondas);
	dr = calcularPartidos(v, m + 1, fin, totalRondas);
	
	if (iz.presentados && dr.presentados && iz.ronda + 1 < totalRondas && dr.ronda + 1 < totalRondas)
		resultado = { iz.jugados + dr.jugados + 1, true, iz.ronda + 1 };
	else if (iz.presentados || dr.presentados)
		resultado = { iz.jugados + dr.jugados, true, iz.ronda + 1 };
	else 
		resultado = { iz.jugados + dr.jugados, false, iz.ronda + 1 };

	return resultado;
}


bool resuelveCaso() {
	int n, numRondas;
	std::cin >> n;

	if (!std::cin) return false;

	std::cin >> numRondas;

	std::vector<std::string> v;

	for (int i = 0; i < n; ++i) {
		std::string aux;
		std::cin >> aux;
		v.push_back(aux);
	}

	std::cout << calcularPartidos(v, 0, n, numRondas).jugados << "\n";

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

	return 0;
}


