//Ejercicio 14
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

struct degradado {
	int suma;
	bool ok;
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
degradado esDegradado(const std::vector<int> &v, const int &ini, const int &fin) {
	if (ini + 1 >= fin - 1) //Vector de dos elementos
		return{ v[ini] + v[fin - 1], v[ini] < v[fin - 1] };

	degradado resultado, iz, dr;
	int m = (ini + fin - 1) / 2;
	iz = esDegradado(v, ini, m + 1);
	dr = esDegradado(v, m + 1, fin);

	resultado.suma = iz.suma + dr.suma;
	resultado.ok = iz.ok && dr.ok && iz.suma < dr.suma;

	return resultado;
}

bool resuelveCaso() {

	int n, m;
	bool vectorDegradado = true;
	std::cin >> n;

	if (!std::cin) return false;

	std::cin >> m;
	std::vector<std::vector<int>> v;

	for (int f = 0; f < n; ++f) {
		std::vector<int> vAux;
		for (int c = 0; c < m; ++c) {
			int aux;
			std::cin >> aux;
			vAux.push_back(aux);
		}
		v.push_back(vAux);
	}

	if (m > 1) { //Si el vector es de un unico elemento no es degradado.
		for (int i = 0; i < n && vectorDegradado; ++i)
			vectorDegradado = esDegradado(v[i], 0, v[i].size()).ok; //Cojo el vector completo y la voy dividiendo en sub-vectores.
	}


	if (vectorDegradado) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif*/

	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/

	return 0;
}
