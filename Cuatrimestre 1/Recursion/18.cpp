//Ejercicio 18
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>

/*
		| c0 n=0
T(n) =  | c0 n=1
		| T(n-1) + c0 n>1
*/
//Coste: O(n)
unsigned long long fibonacci(const int &n, const unsigned long long &n1, const unsigned long long &n2) {
    
	if (n == 1) return n1;
	else return fibonacci(n - 1, n1 + n2, n1);
}

unsigned long long fibonacci(const int &n) {
	if (n == 0) return 0;
	else return fibonacci(n, 1, 0);
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

	if (!std::cin) return false;
    
	std::cout << fibonacci(n) << "\n";
    
	return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	
	while(resuelveCaso());
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
    return 0;
}

