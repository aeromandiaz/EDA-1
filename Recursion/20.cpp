//Ejercicio 20
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

using tMatriz = std::vector<std::vector<int>>;

//Coste O(a*b)
int calcularSumas(const std::vector<int> &v, const int &i, const int &k, const int &s, tMatriz &aux) {
    if (k - 1 == 0 && v[k - 1] == s) return 1; //Si el primer elemento es el que busco
    else if(k < v.size()) {
        if(v[k] == s) return 1; //Si el emento actual es la suma
        if (aux[i].empty()) //Si la matriz está vacía, rellenamos con el primer valor del vector más el siguiente
            aux[i].push_back(v[i] + v[k]);
        else if (aux[i].back() + v[k] <= s) //Si el ultimo valor de la matriz mas el siguiente del vector es menor que la suma, lo agregamos
            aux[i].push_back(aux[i].back() + v[k]);
        if (aux[i].back() == s || v[i] + v[k] == s) return 1;
        return calcularSumas(v, i, k + 1, s, aux);
    }
    else if (v[k - 1] == s) return 1; //Si el elemento final del vector es la suma
    
    return 0;
}

int calcularSumas(const std::vector<int> &v, const int &s) {
    if (s == 0) return 0;
    if (v.size() == 1) return 1;
    
    tMatriz aux(v.size());
    int sum = 0;
    
    for (int i = 0; i < v.size(); ++i)
        sum += calcularSumas(v, i, i+1, s, aux);
    
    return sum;
}

bool resuelveCaso() {
    int n, s;
    std::cin >> n;
    
    if(!std::cin) return false;
    
    std::cin >> s;
    std::vector<int> v;
    
    for (int i = 0; i < n; ++i) {
        int aux;
        std::cin >> aux;
        v.push_back(aux);
    }
    
    std::cout << calcularSumas(v, s) << "\n";
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

