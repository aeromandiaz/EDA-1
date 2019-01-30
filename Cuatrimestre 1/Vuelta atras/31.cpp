//Ejercicio 31
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector<std::vector<int>>;

bool esValida(const tMatriz &matriz, const int &mejorPunt, const int &pMin, 
	const int &presMax , const int &k, const int &i, 
	const int &sueldoAc, const int &puntAc) {

	if (matriz[k][i] < pMin ) return false;
	if (sueldoAc > presMax) return false;

	return true;
}

void vueltaAtras(const tMatriz &matriz, const std::vector<int> &sueldos, int &mejorPunt, int &presupuesto,
	const int &puntMin, const int &presMax, int k, std::vector<bool> &marcas, std::vector<int> &aux,
	std::vector<int> &sol, int sueldoAc, int puntAc, bool &haySol) {

	for (int i = 0; i < sueldos.size(); ++i) {
		if (!marcas[i]) {
			aux[k] = i;
			sueldoAc += sueldos[i];
			puntAc += matriz[k][i];
			if (esValida(matriz, mejorPunt, puntMin, presMax, k, i, sueldoAc, puntAc)) {
				if (k + 1 == sol.size()) { //Es solución.
					if (puntAc > mejorPunt) { //Es solución mejor.
						mejorPunt = puntAc;
						haySol = true;
						presupuesto = sueldoAc;
						for (int z = 0; z < aux.size(); ++z) sol[z] = aux[z];
					}
				}
				else {
					marcas[i] = true;
					vueltaAtras(matriz, sueldos, mejorPunt, presupuesto, puntMin, presMax,
						k + 1, marcas, aux, sol, sueldoAc, puntAc, haySol);
					marcas[i] = false;
				}
			}
			sueldoAc -= sueldos[i];
			puntAc -= matriz[k][i];
		}
	}

}


bool resuelveCaso() {
	int n, a, p, m;
	std::cin >> n >> a >> p >> m;

	if (n == 0 && a == 0 && p == 0 && m == 0) return false;

	std::vector<int> sueldos(a), aux(n), sol(n);
	for (int i = 0; i < a; ++i)
		std::cin >> sueldos[i];

	tMatriz matriz (n, std::vector<int>(a));

	for (int i = 0; i < n; ++i) {
		for (int c = 0; c < a; ++c)
			std::cin >> matriz[i][c];
	}

	int puntuacionMejor = 0, presupuestoFinal = 0;

	std::vector<bool> marcas(a, false);
	bool haySol = false;
	vueltaAtras(matriz, sueldos, puntuacionMejor, presupuestoFinal, m, p, 0, marcas, aux, sol, 0, 0, haySol);

	std::cout << puntuacionMejor << " " << presupuestoFinal << "\n";
	if (haySol) {
		for (int i = 0; i < sol.size(); ++i)
			std::cout << i << " " << sol[i] << "\n";
	}

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
