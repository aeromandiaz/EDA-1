#include <iostream>
#include <fstream>
#include <vector>

/*
 
 method resuelve(v: array<int>, d: int, n: int) returns (esCreciente : bool, ddiver : bool)
    requires v.Length > 0
    ensures...
*/
//Coste O(n)
bool resuelve(const std::vector<int> &v, const int &d, const int &n) {
    
    int repetido = 1, anterior = v[0], i = 1;
    bool esCreciente = true, ddiver = true;
    
    
    while (i < v.size() && esCreciente && ddiver)
    /*
     invariant 0 <= i <= v.Length
     decreases v.Length - i
     */
    {
        if (anterior > v[i] || anterior + 1 < v[i])
            esCreciente = false;
        else if (anterior == v[i]) {
            ++repetido;
            if (repetido > d) ddiver = false;
        } else {
            repetido = 1;
            anterior = v[i];
        }
        ++i;
    }
    
    return esCreciente && ddiver;
}

void resuelveCaso() {
    int d, n;
    std::cin >> d >> n;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    if (resuelve(v,d,n))
        std::cout << "SI\n";
    
    else
        std::cout << "NO\n";
}

int main(){
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
