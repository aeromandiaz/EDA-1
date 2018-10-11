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
bool buscarPos(const std::vector<unsigned int> &v, const int &ini, const int &fin, const int &find,
	unsigned int &res) {
	if (ini + 1 == fin) { // Si el vector tiene un elemento
		res = v[ini];
		return v[ini] == find + ini; //Retorno el valor si se cumple
	}

	int m = (ini + fin - 1) / 2;

	if (v[m] == find + m) { //Retorno el valor si se cumple
		res = v[m];
		return true;
	}

	if (v[m] > find + m) //Si el elemento actual es mayor que su posicion más el cantado busco en los anteriores
		return buscarPos(v, ini, m + 1, find, res);
	else 
		return buscarPos(v, m + 1, fin, find, res);
	return false; 
}

void resuelveCaso() {

	std::vector<unsigned int> v;
	unsigned int n, find, res = 0;
	std::cin >> n >> find;


	for (int i = 0; i < n; ++i) {
		unsigned int aux;
		std::cin >> aux;
		v.push_back(aux);
	}

	if (!buscarPos(v, 0, n, find, res))
		std::cout << "NO\n";
	else 
		std::cout << res << '\n';

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

	for (int i = 0; i < n; ++i) {
		resuelveCaso();
	}

		// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}