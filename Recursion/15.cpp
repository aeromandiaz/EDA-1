//Ejercicio 15
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

struct sol {
	unsigned long long int num;
	unsigned int pot;

};


unsigned long long int resuelveComplementario(const unsigned long long int &n) {
    
    if (n <= 9) return 9 - n;
    
	return (9 - (n % 10)) + resuelveComplementario(n / 10) * 10;
}

sol invierteComplementario(const unsigned long long int &n) {

	if (n <= 9) return { 9 - n, 1 };

	sol numInv = invierteComplementario(n / 10);
	numInv.pot *= 10;

	numInv.num += (9 - (n % 10)) * numInv.pot;

	return numInv;
}

//        | c0 si n == 1
// T(n)   |
//        | 2T(n/10) + c0 si n > 1
//
//    Despliegue:
//    T(n) = 2T(n/10) + c0 = 2^2T(n/(10^2)) + c0 + c0 = 2^3T(n/(10^3)) + c0 + c0 + c0 =...
//    = 2^kT(n/(10^k)) + k*c0
//    Por tanto, nlog(n) + n*c0
//
//Coste O(nlogn)
void resuelveCaso() {
    
    int casos;
    unsigned long long int n;
    std::cin >> casos;
    
    for (int i = 0; i < casos; ++i) {
        std::cin >> n;
		std::cout << resuelveComplementario(n) << " " << invierteComplementario(n).num << "\n";
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    resuelveCaso();
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
#endif
    
    return 0;
}
