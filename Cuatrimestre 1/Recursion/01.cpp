#include <iostream>

unsigned long long int prod(const unsigned long long int &a, const unsigned long long int &b) {

	if (b == 0) return 0;
	else if (b == 1) return a;
	else if (b % 2 == 0) return prod(2 * a, b / 2);
	else return prod(2 * a, b / 2) + a;
}

void resuelveCaso() {
	unsigned long long int a, b;
	std::cin >> a >> b;

	std::cout << prod(a, b) << '\n';
}

int main() {
	int casos = 0;
	std::cin >> casos;

	for (int i = 0; i < casos; ++i) {
		resuelveCaso();
	}
	return 0;
}