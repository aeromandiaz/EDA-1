#include <iostream>
#include <string>

struct sol {
	unsigned int numero;
	int pot;
	sol() {
		numero = 0; pot = 1;
	}
	sol(const unsigned int &num, const int &p){
		numero = num; pot = p;
	}
};

sol invertir(const unsigned int &n) {

	if (n <= 9) {
		sol numInvertido(n, 1);
		return numInvertido;
	}
	sol numInvertido = invertir(n / 10);
	numInvertido.pot *= 10;
	numInvertido.numero += n % 10 * numInvertido.pot;
	

	return numInvertido;
}

bool resuelveCaso() {
	unsigned int a;
	std::cin >> a;
	if (!std::cin) return false;

	std::cout << invertir(a).numero << '\n';
	return true;
}

int main() {
	while (resuelveCaso()) {

	}
}