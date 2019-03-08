//Ejercicio 06
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <stack>


bool compruebaEquilibrio(std::stack<char> &pila) {
	char ultimo = pila.top(); pila.pop();

	if (pila.empty())
		return false;
	else if (ultimo == ']' && pila.top() == '[')
		pila.pop();
	else if (ultimo == ')' && pila.top() == '(')
		pila.pop();
	else if (ultimo == '}' && pila.top() == '{')
		pila.pop();
	else
		return false;

	return true;
}


bool resuelveCaso() {
	std::string entrada;

	getline(std::cin, entrada);

	if (!std::cin) return false;

	std::stack<char> pila;
	bool continua = true;

	for (int i = 0; i < entrada.size() && continua; ++i) {
		if (entrada[i] == '[' || entrada[i] == '(' || entrada[i] == '{')
			pila.push(entrada[i]);
		if (entrada[i] == ']' || entrada[i] == ')' || entrada[i] == '}') {
			pila.push(entrada[i]);
			continua = compruebaEquilibrio(pila);
		}
	}

	if (continua && pila.empty()) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

}
