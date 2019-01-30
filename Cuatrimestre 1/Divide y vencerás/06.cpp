#include <iostream>
#include <vector>
#include <string>
#include <fstream>


//		| Caso base: c0
// T(n) |
//		| Caso recursvo: T(n/2) + c0
//Coste O(logn)
char buscarPreso(const std::vector<char> &v, const int &ini, const int &fin, const char &pIni, const char &pFin) {
	if (ini + 1 == fin) { // Si el vector tiene un elemento
		if (fin == v.size() && v[fin - 1] != pFin) //Si el elemento final es el que se ha fugado.
			return char(v[ini] + 1);
		return char(v[ini] - 1);
	}
	int m = (ini + fin - 1) / 2; 
	if (v[m] - pIni != m) { //Si algún preso de las primeras posiciones antes de la mitad se ha escapado.
		return buscarPreso(v, ini, m + 1, pIni, pFin);
	}
	else {
		return buscarPreso(v, m + 1, fin, pIni, pFin);
	}
}

void resuelveCaso() {
	std::vector<char> v;
	char ini, fin;
	std::string temp;

	std::cin >> ini >> fin;
	std::cin.ignore();
	std::getline(std::cin, temp);

	while (temp != "") {
		v.push_back(temp[0]);
		temp.replace(0, 1, "");
		temp.replace(0, 1, "");
	}

	std::cout << buscarPreso(v, 0, v.size(), ini, fin) << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif 


		int numCasos;
		std::cin >> numCasos;
		for (int i = 0; i < numCasos; ++i)
			resuelveCaso();


		// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}