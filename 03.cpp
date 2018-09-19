#include <iostream>
#include <string>

struct sol {
	unsigned long long int numero = 0;
	int pot = 0;
};

sol invertir(const unsigned int &n) {

	sol numInvertido;
	unsigned long long int aux = 1;
	unsigned int i = n;

	if (n == 0) 
		return numInvertido;
	while (i / 10 > 0) {
		aux *= 10;
		i /= 10;
	}
	numInvertido.pot = n % 10;
	numInvertido.numero = invertir(n / 10).numero + numInvertido.pot * aux;
	
	return numInvertido;
}

void resuelveCaso() {
	unsigned int a;
	std::cin >> a;

	std::cout << invertir(a).numero << '\n';
}

int main() {
	int casos = 0;
	std::cin >> casos;

	for (int i = 0; i < casos; ++i) {
		resuelveCaso();
	}
	return 0;
}