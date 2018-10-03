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
unsigned int buscarImpar(const std::vector<unsigned int> &v, const int &ini, const int &fin) {
	if (ini + 1 == fin) // Si el vector tiene un elemento
		return v[ini];

	int m = (ini + fin - 1) / 2;

	if (v[m] % 2 != 0) return v[m];
	unsigned int sum = 0;

	for (int i = 0; i < m; ++i)
		sum += v[i];

	if (sum % 2 != 0) 
		return buscarImpar(v, ini, m + 1);
	else
		return buscarImpar(v, m + 1, fin);
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

	std::cout << buscarImpar(v, 0, v.size()) << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif */

		while(resuelveCaso());


		// Para restablecer entrada. Comentar para acepta el reto
	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}