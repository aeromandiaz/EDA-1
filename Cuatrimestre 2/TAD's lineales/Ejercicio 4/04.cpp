//Ejercicio 04
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

class Monomio {
    int coeficiente;
    int exponente;
    
public:
    
    Monomio(): coeficiente(0), exponente(0) { }
    
    Monomio(int coef, int ex) : coeficiente(coef), exponente(ex) { }
    
    int getCoeficiente() const { return coeficiente; }
    
    int getExponente() const { return exponente; }
};

template<class T>
class Polinomio {
    std::vector<T> _p;
    
public:
    
    std::vector<T> p() const{ return _p; }
    
    void insertaMonomio (const T &m) {  _p.push_back(m); }
    
    int evalua(const int &x) const{
        int sol = 0;
        for (int i = 0; i < _p.size(); i++)
            sol += _p.at(i).getCoeficiente() * pow(x, _p.at(i).getExponente());
        
        return sol;
    }
    
};


bool resuelveCaso() {
    int C, E;
    Monomio monomio;
    Polinomio<Monomio> p;
    
    std::cin >> C >> E;
    
    if (!std::cin) return false;
    
    while (C != 0 || E != 0) {
        if (C != 0 || E != 0) {
            monomio = Monomio(C, E);
            p.insertaMonomio(monomio);
        }
        std::cin >> C >> E;
    }
    
    int N, aux;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> aux;
        std::cout << p.evalua(aux);
        if (i + 1 != N)
            std::cout << " ";
    }
    
    std::cout << "\n";
    
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
