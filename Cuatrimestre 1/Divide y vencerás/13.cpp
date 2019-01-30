//Ejercicio 13
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

struct par {
	int menor;
	int mayor;
	bool ord;
};

//        | c0 si n == 1
// T(n)   |
//        | 2T(n/2) + c0 si n > 1
//
//    Despliegue:
//    T(n) = 2T(n/2) + c0 = 2^2T(n/(2^2)) + 2c0 + c0 = 2^3T(n/(2^3)) + 2^2c0 + c0 =...
//    = 2^kT(n/(2^k)) + 2*kc0 + 2^(k-1)c0 + 2^(k-2)c0 + ... + 2^(k-n)c0 
//
//Coste O(n)
par dividir(const std::vector<int> &v, const int &ini, const int &fin) {
	if (ini + 1 >= fin - 1) { //Vector de dos elementos
		if (v[ini] <= v[fin - 1]) return{ v[ini], v[fin - 1], true };
		else return { v[fin - 1], v[ini], false };
	}

	par p, iz, dr;

	int m = (ini + fin - 1) / 2;
	iz = dividir(v, ini, m + 1);

	if (!iz.ord) {
		p.ord = false;
		return p;
	}

	dr = dividir(v, m + 1, fin);

	if (!dr.ord) {
		p.ord = false;
		return p;
	}
	p.ord = iz.mayor <= dr.mayor && iz.menor <= dr.menor;

	p.menor = std::min(iz.menor, dr.menor);
	p.mayor = std::max(iz.mayor, dr.mayor);

	return p;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<int> v;

	while (n != 0) {
		v.push_back(n);
		std::cin >> n;
	}

	if (v.size() == 1) {
		std::cout << "SI\n";
		return true;
	}

	par iz = dividir(v, 0, v.size() / 2);
	par dr = dividir(v, (v.size() / 2), v.size());

	if (iz.ord && dr.ord && iz.menor <= dr.menor && iz.mayor <= dr.mayor) std::cout << "SI\n";
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

	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

