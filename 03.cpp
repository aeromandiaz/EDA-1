#include <iostream>
#include <string>

struct sol {
	unsigned long long int numero;
	int pot;
	sol() {
		numero = 0; pot = 0;
	}
	sol(const unsigned long long int &num, const int &p){
		numero = num; pot = p;
	}
};

sol invertir(const unsigned long long int &n) {

	unsigned long long int aux = 1;

	if (n <= 9) {
		sol numInvertido(n, n % 10);
		return numInvertido;
	}
	sol numInvertido;
	while (n / (aux * 10))
		aux *= 10;
	numInvertido.pot = n % 10;
	numInvertido.numero = invertir(n / 10).numero + numInvertido.pot * aux;
	
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