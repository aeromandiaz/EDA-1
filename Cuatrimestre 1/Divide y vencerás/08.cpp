#include <iostream>
#include <vector>

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
int buscarMinimo(const std::vector<int> &v, const int &ini, const int &fin) {
	if (ini + 1 == fin) // Si el vector tiene un elemento
		return v[ini];

	int m = (ini + fin - 1) / 2;

	if (v[ini] < v[m]) //Si el elemento inicial es menor que el actual
		return buscarMinimo(v, ini, m + 1);
	else if (v[m + 1] < v[m]) //Si el elemento justo siguiente es menor que el actual
		return buscarMinimo(v, m + 1, fin);
	return v[m]; //Si es el menor
}



bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (!std::cin) return false;

	std::vector<int> v;

	for (int i = 0; i < n; ++i) {
		int aux;
		std::cin >> aux;
		v.push_back(aux);
	}

	std::cout << buscarMinimo(v, 0, n) << '\n';

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
