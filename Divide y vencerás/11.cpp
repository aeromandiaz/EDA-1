//Ejercicio 11
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
unsigned int buscarIz(const std::vector<unsigned int> &v, const int &ini, const int &fin, const int &elemento) {
	if (ini > fin) return ini;
	else if (ini + 1 == fin) return ini;
	else { //  Vector  de dos o mas  elementos
		int  m = (ini + fin - 1) / 2;
		if (v[m] < elemento) return  buscarIz(v, m + 1, fin, elemento);
		return buscarIz(v, ini, m + 1, elemento);   //  incluye  la mitad
	}
}

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
unsigned int buscarDr(const std::vector<unsigned int> &v, const int &ini, const int &fin, const int &elemento) {
	if (ini > fin) return ini;
	else if (ini + 1 == fin) return ini;
	else { //  Vector  de dos o mas  elementos
		int  m = (ini + fin) / 2;
		if (elemento < v[m]) return  buscarDr(v, ini, m, elemento);
		return buscarDr(v, m, fin, elemento);   //  incluye  la mitad
	}
}

//		| c0 si n == 1
// T(n) |
//		| 2T(n/2) + c0 si n > 1
//
//	Despliegue:
//	T(n) = 2T(n/2) + c0 = 2^2T(n/(2^2)) + c0 + c0 = 2^3T(n/(2^3)) + c0 + c0 + c0 =...
//	= 2^kT(n/(2^k)) + k*c0
//	Por tanto, n + n*c0
//
//Coste O(n)
bool resuelveCaso() {

	unsigned int n, altura;
	std::cin >> n;

	if (!std::cin) return false;

	std::cin >> altura;

	std::vector<unsigned int> v;

	for (int i = 0; i < n; ++i) {
		unsigned int aux;
		std::cin >> aux;
		v.push_back(aux);
	}

	int iz = buscarIz(v, 0, v.size(), altura);
	if (iz == v.size() || v[iz] != altura) std::cout << "NO EXISTE\n";
	else { // Si  existe  el  elemento  busca  en el lado  derecho
		int dr = buscarDr(v, 0, v.size(), altura);
		if (iz == dr) std::cout << iz << "\n";
		else  std::cout << iz << " " << dr << "\n";
	}
	
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