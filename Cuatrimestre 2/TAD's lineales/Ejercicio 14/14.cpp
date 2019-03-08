//Ejercicio 14
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <stack>
#include <queue>


bool comprobarVocal(const char &c) {
    switch(std::tolower(c)) {
        case 'a': return true;
        case 'e': return true;
        case 'i': return true;
        case 'o': return true;
        case 'u': return true;
        default: return false;
    }
}

bool resuelveCaso() {
    
    std::string frase, sol = "";
    getline(std::cin, frase);
    
    std::queue<char> cola;
    std::stack<char> pila;
    
    if (!std::cin) return false;
    
    for (int i = 0; i < frase.size(); ++i) {
        if (i % 2 == 0)
            cola.push(frase[i]);
        else
            pila.push(frase[i]);
    }
    
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }
    
    for (int i = 0; !cola.empty(); ++i) {
        if (comprobarVocal(cola.front())) {
            while (!pila.empty()) {
                sol += pila.top();
                pila.pop();
            }
            sol += cola.front();
        } else
            pila.push(cola.front());
        cola.pop();
    }
    
    while (!pila.empty()) {
        sol += pila.top();
        pila.pop();
    }
    
    std::cout << sol << "\n";
    
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
