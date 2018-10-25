//Ejercicio 24
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

enum tColores { AZUL, ROJO, VERDE, VACIO };

tColores parserColor(int n) {
	return tColores(n);
}

std::ostream& operator << (std::ostream &o, const std::vector<tColores> &v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == ROJO)
			o << "rojo";
		else if(v[i] == AZUL)
			o << "azul";
		else
			o << "verde";
		if (i + 1 == v.size())
			o << "\n";
		else
			o << " ";
	}
	return o;
}

bool esValida(const int &k, const int &n, const std::vector<tColores> &v, const int &r, const int &g, const int &b) {
	return k + 1 < n && (g <= b || g == 0 && b == 0) && (k - 1 == 0 ||
		((v[k - 1] != VERDE && v[k] != VERDE) || (v[k - 1] == VERDE && v[k] != VERDE) || (v[k - 1] != VERDE && v[k] == VERDE)));
}

void calcularCombinaciones(std::vector<tColores> &v, const int &n, const int &k, int r, int g, int b, bool &sol, 
	const int &ROJAS, const int &AZULES, const int &VERDES) {

	for (int i = 0; i < 3; ++i) {
		if ((tColores(i) == ROJO && r < ROJAS) || (tColores(i) == VERDE && g < VERDES) || (tColores(i) == AZUL && b < AZULES)) {
			v[k] = tColores(i);
			if (parserColor(i) == ROJO && r < ROJAS)
				++r;
			else if (parserColor(i) == VERDE && g < VERDES)
				++g;
			else if (b < AZULES)
				++b;
			if (k + 1 == n && (b + g) < r && (g <= b || g == 0 && b == 0)) { //Es solución
				std::cout << v; //con sobrecarga para el vector.
				sol = true;
			}
			else if (esValida(k, n, v, r, g, b))
				calcularCombinaciones(v, n, k + 1, r, g, b, sol, ROJAS, AZULES, VERDES);
			if (parserColor(i) == ROJO)
				--r;
			else if (parserColor(i) == VERDE)
				--g;
			else
				--b;
		}
	}
}


bool resuelveCaso() {
	int altura, r, g, b;
	std::cin >> altura >> b >> r >> g;

	if (altura == 0 && b == 0 && r == 0 && g == 0) return false;

	bool sol = false;

	std::vector<tColores> v(altura, VACIO);
	v[0] = ROJO;

	calcularCombinaciones(v, altura, 1, 1, 0, 0, sol, r, b, g);
	if (!sol) std::cout << "SIN SOLUCION\n";

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

	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}

