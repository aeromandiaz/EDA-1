#include <iostream>
#include <fstream>
#include <vector>

/*
 
 method resuelve(v: array<int>) returns (esCreciente : bool)
    requires v.Length > 0
    requires forall k:: 0 < k < v.Length ==> v[k-1] <= v[k]
    ensures...
*/
//Coste O(n)
bool resuelve(const std::vector<int> &v) {
    
    int maxSize = 1, sizeEscaleraAnt = 1, i = 1;
    bool esCreciente = true;
    
    int peldanhoAnt = v[0];
    
    while (i < v.size() && esCreciente)
    /*
     invariant 0 <= i <= v.Length
     decreases v.Length - i
     */
    {
        if (peldanhoAnt == v[i])
            ++sizeEscaleraAnt;
        else if (maxSize > sizeEscaleraAnt)
            esCreciente = false;
        else {
            maxSize = sizeEscaleraAnt;
            sizeEscaleraAnt = 1;
            peldanhoAnt = v[i];
        }
        ++i;
    }
    
    if (maxSize > sizeEscaleraAnt)
        esCreciente = false;
    
    return esCreciente;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if (n == 0) return false;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    if (resuelve(v))
        std::cout << "SI\n";
    
    else
        std::cout << "NO\n";
    
    return true;
}

int main(){
    
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
