#include <iostream>
#include <vector>


//		| Caso base: c0
// T(n) |
//		| Caso recursvo: T(n/2) + c0
//Coste O(logn)
int buscarMinimo(const std::vector<int> &v, const int &ini, const int &fin) {
	if (ini + 1 == fin) //Vector de 1 elemento
		return v[ini];
	int m = (ini + fin - 1) / 2; 
	if (m > 0 && v[m-1] < v[m]) //Si elemento anterior es menor que el actual
		return buscarMinimo(v, ini, m);
	else if (m < v.size() && v[m + 1] < v[m]) //Si elemento siguiente es menor que el actual
		return buscarMinimo(v, m + 1, fin);
	return v[m]; //Ninguno de los anteriores, asi que este es el elemento menor
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

	std::cout << buscarMinimo(v, 0, v.size()) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}