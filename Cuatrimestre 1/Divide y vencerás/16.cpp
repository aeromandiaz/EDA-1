//Ejercicio 16
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int mezcla(std::vector<int> &v, std::vector<int> &temp, const int &ini, const int &m, const int &fin) {
	int i = ini, j = m, k = ini;
	int cuenta = 0;

	while ((i <= m - 1) && (j <= fin)) {
		if (v[i] <= v[j]) 
			temp[k++] = v[i++];
		else {
			temp[k++] = v[j++];
			cuenta = cuenta + (m - i);
		}
	}

	while (i <= m - 1)
		temp[k++] = v[i++];

	while (j <= fin)
		temp[k++] = v[j++];

	for (i = ini; i <= fin; i++)
		v[i] = temp[i];

	return cuenta;

}


//El coste lo subiré proximamente
int mergeSort(std::vector<int> &v, std::vector<int> &temp, int ini, int fin) {
    int m, res = 0;
	if (ini < fin) { // mas de 1 elemento
        m = (ini + fin) / 2;
		res = mergeSort(v, temp, ini, m);
		res += mergeSort(v, temp, m + 1, fin);
		res += mezcla(v, temp, ini, m + 1, fin);
	}
	return res;
}

bool resuelveCaso() {
    
    int n;
    std::cin >> n;
    
    if (!std::cin) return false;

    std::vector<int> v;
    int res = 0;
    
    for (int i = 0; i < n; ++i) {
        int aux;
        std::cin >> aux;
        v.push_back(aux);
    }
    
	std::vector<int> aux(n);
	std::cout << mergeSort(v, aux, 0, n - 1) << "\n";
    
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
    system("PAUSE");
#endif
    
    return 0;
}

