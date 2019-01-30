#include <iostream>

unsigned long long int eliminarPares(const unsigned long long int &n) {

	if (n == 0)	return 0;

	unsigned long long int aux = n % 10, numero = eliminarPares(n / 10);
	if (aux % 2 != 0) return (numero * 10) + aux;

	return numero;
}

bool resuelveCaso() {
	unsigned long long int a;
	std::cin >> a;

	if (!std::cin) return false;

	std::cout << eliminarPares(a) << '\n';
	return true;
}

int main() {
	while(resuelveCaso()) {
	}
	return 0;
}