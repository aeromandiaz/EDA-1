//Ejercicio 10
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

//		| c0 si n == 1
// T(n) |
//		| T(n/2) + c0 si n > 1
//
//	Despliegue:
//	T(n) = T(n/2) + c0 = T(n/(2^2)) + c0 + c0 = T(n/(2^3)) + c0 + c0 + c0 =...
//	= T(n/(2^k)) + k*c0
//	Por tanto, log(n) + n*c0
//
//Coste O(logn)
unsigned int buscarRepes(const std::vector<unsigned int> &v, const int &ini, const int &fin) {
	if (ini + 1 == fin) // Si el vector tiene un elemento
		return 1;

	int m = (ini + fin - 1) / 2, iz = 1, dr = 1;

	if (v[ini] == v[fin - 1]) return 1; //Si el primer elemento y el ultimo son iguales. Todo el vector es de un num.
	if (v[ini] != v[m]) iz = buscarRepes(v, ini, m + 1);
	if (v[fin - 1] != v[m]) {
		dr = buscarRepes(v, m + 1, fin);
	}
	if (v[m] == v[m + 1]) //Para evitar repetir la cuenta.
		return iz + dr - 1;

	return iz + dr;
}

bool resuelveCaso() {

	unsigned int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<unsigned int> v;

	for (int i = 0; i < n; ++i) {
		unsigned int aux;
		std::cin >> aux;
		v.push_back(aux);
	}

	std::cout << buscarRepes(v, 0, v.size()) << '\n';

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
		system("PAUSE");
	#endif

	return 0;
}