//Ejercicio 19
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

//Coste O(a*b)
int calcularCombinatorio(const int &a, const int &b, std::vector<std::vector<int>> &matriz) {
    if (b == 0 || a == b) return matriz[a][b] = 1;
    else if (b == 1 || b == a - 1) return matriz[a][b] = a;
    if (matriz[a - 1][b - 1] == -1) matriz[a - 1][b - 1] = calcularCombinatorio(a - 1,b - 1, matriz);
    if (matriz[a - 1][b] == -1) matriz[a - 1][b] = calcularCombinatorio(a - 1, b, matriz);
    return matriz[a][b] = matriz[a - 1][b - 1] + matriz[a - 1][b];
}

bool resuelveCaso() {
    int a, b;
    std::cin >> a;
    
    if(!std::cin) return false;
    
    std::cin >> b;
    std::vector<std::vector<int>> matriz(a + 1, std::vector<int>(b + 1 , -1));
    
    std::cout << calcularCombinatorio(a, b, matriz) << "\n";
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

