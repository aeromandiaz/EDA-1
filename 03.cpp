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

	//unsigned long long int aux = 1;

	if (n <= 9) {
		sol numInvertido(n, 10);
		return numInvertido;
	}
	sol numInvertido;
	/*while (n / (aux * 10))
		aux *= 10;*/
	numInvertido.pot = n % 10;
	//numInvertido.numero = invertir(n / 10).numero + numInvertido.pot * aux;
	numInvertido.numero = invertir(n / 10).numero + numInvertido.pot * (n % 10);
	numInvertido.pot *= 10;

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