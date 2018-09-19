#include <iostream>

int eliminarPares(const unsigned int &n) {

	if (n == 0)	return 0;

	if ((n % 10) % 2 != 0) return (eliminarPares(n / 10) * 10) + (n % 10);

	return eliminarPares(n / 10);
}

void resuelveCaso() {
	unsigned long long int a;
	std::cin >> a;

	std::cout << eliminarPares(a) << '\n';
}

int main() {
	int casos = 0;
	std::cin >> casos;

	for (int i = 0; i < casos; ++i) {
		resuelveCaso();
	}
	return 0;
}