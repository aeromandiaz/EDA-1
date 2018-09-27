#include <iostream>
#include <vector>
#include <fstream>

//		| c0 si n = impar
// T(n) |
//		| T(n + 1) + c0 si n = par
//
//	Despliegue:
//	T(n) = T(n+1) + c0 = T(n+2) + c0 + c0 = T(n+3) + c0 + c0 + c0 =...
//	= T(k+n) + k*c0
//	Por tanto, si k = impar --> T(c0) + n*c0 = c0 + n*c0
//
//Coste O(n)
unsigned int buscarImpar(const std::vector<unsigned int> &v, const int &pos) {
	if (pos == v.size()) // vector de 1 elemento 
		return v[pos]; 
	else {
		if (v[pos]%2 != 0) return v[pos];
		return buscarImpar(v, pos + 1);
	}
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

	std::cout << buscarImpar(v, 0) << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif */

		while(resuelveCaso());


		// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}