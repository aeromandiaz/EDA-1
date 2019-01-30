#include <iostream>
#include <string>

std::string transformar(const unsigned int &a, const std::string &val) {

	if (a == 0) return "0" + val;
	else if (a == 1) return "1" + val;
	return transformar(a / 2, std::to_string(a % 2) + val);
}

void resuelveCaso() {
	unsigned int a;
	std::cin >> a;

	std::cout << transformar(a, "") << '\n';
}

int main() {
	int casos = 0;
	std::cin >> casos;

	for (int i = 0; i < casos; ++i) {
		resuelveCaso();
	}
	return 0;
}