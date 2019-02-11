//Ejercicio 06
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

class ParentesisEquilibrados {
    std::stack<char> pila;
    bool equilibrado;
    
public:
    ParentesisEquilibrados(): equilibrado(true) {};
    
    bool getEquilibrada() const { return equilibrado; };
    
    void inserta(const char &c) {  pila.push(c); }
    
    void compruebaEquilibrio() {
        if (!pila.empty()) {
            if (pila.top() == ']' || pila.top() == '}' || pila.top() == ')') {
                char ultimo = pila.top(); pila.pop();
                
                if (pila.empty())
                    equilibrado = false;
                else if (ultimo == ']' && pila.top() == '[')
                    pila.pop();
                else if (ultimo == ')' && pila.top() == '(')
                    pila.pop();
                else if (ultimo == '}' && pila.top() == '{')
                    pila.pop();
                else
                    equilibrado = false;
            }
        }
    }
    
    void fin() {
        if (!pila.empty()) equilibrado = false;
    }
    
};


bool resuelveCaso() {
    std::string entrada;
    ParentesisEquilibrados p;
    
    getline(std::cin, entrada);
    
    if (!std::cin) return false;
    
    char tmp;
    
    for (int i = 0; i < entrada.size() && p.getEquilibrada(); ++i) {
        tmp = entrada[i];
        if (tmp == '[' || tmp == ']' || tmp == '(' || tmp == ')' || tmp == '{' || tmp == '}') {
            p.inserta(tmp);
            p.compruebaEquilibrio();
        }
    }
    
    if (p.getEquilibrada()) p.fin();
    
    if (p.getEquilibrada()) std::cout << "SI\n";
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
    
    while(resuelveCaso());
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
