//Ejercicio 07
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>


bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if (!std::cin) return false;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    std::stack<int> pila;
    bool continua = true;
    int med = -1;
    pila.push(v[n - 1]);
    
    for (int i = n - 2; i >= 0 && continua; --i) {
        if (v[i] < pila.top()) {
            if (!pila.empty() && med > 0) {
                if (v[i] > med)
                    med = v[i];
                else if (v[i] < pila.top() && pila.top() > med)
                    continua = false;
            }
            pila.push(v[i]);
        }
        
        else if (v[i] > pila.top()){
            int tmp = v[i];
            while(!pila.empty() && pila.top() < tmp) {
                med = std::max(med, pila.top());
                pila.pop();
            }
            pila.push(v[i]);
        }
    }
    
    if (!continua) std::cout << "ELEGIR OTRA\n";
    else std::cout << "SIEMPRE PREMIO\n";
    
    
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
    
}
