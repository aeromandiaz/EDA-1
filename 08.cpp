#include <iostream>
#include <vector>

int particion(std::vector<int> &v, const int &ini, const int &fin) {
	int pivot = v[fin];
	int aux = (ini - 1);

	for (int i = ini; i <= fin - 1; ++i) {
		if (v[i] <= pivot) {
			++aux;
			int temp = v[aux];
			v[aux] = v[i];
			v[i] = temp;
		}
	}
	int temp = v[fin];
	v[fin] = v[aux + 1];
	v[aux + 1] = temp;
 	
	return (aux + 1);
}


void quickSort(std::vector<int> &v, int ini, int fin) {
	if (ini < fin) {
		int pivot = particion(v, ini, fin);

		quickSort(v, ini, pivot - 1);
		quickSort(v, pivot + 1, fin);
	}
}



bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if(!std::cin) return false;
    
    std::vector<int> v;
    
    for (int i = 0; i < n; ++i) {
        int aux;
        std::cin >> aux;
        v.push_back(aux);
    }

	quickSort(v, 0, n-1);
	std::cout << v[0] << '\n';
    
    return true;
}

int main() {
    
    while(resuelveCaso());
    
    return 0;
}
