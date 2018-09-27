#include <iostream>
#include <vector>
#include <fstream>

//Coste O(n)
unsigned int buscarPos(const std::vector<unsigned int> &v, const int &pos, const int &find) {
	if (pos < v.size()) {
		if(pos + find == v[pos]) return v[pos];
		return buscarPos(v, pos + 1, find);
	}
	else
		return -1;
}

void resuelveCaso() {

	std::vector<unsigned int> v;
	unsigned int n, find, res;
	std::cin >> n >> find;


	for (int i = 0; i < n; ++i) {
		unsigned int aux;
		std::cin >> aux;
		v.push_back(aux);
	}

	res = buscarPos(v, 0, find);

	if (res == -1) 
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