#include <iostream>
#include <fstream>
#include <vector>

/*
function  countTramos (s : seq <int>) : int
ensures s == [] ==> countTramos(s) == 0
ensures |s| == 2 ==> countTramos(s) == 1
ensures s != [] && s[0] >= s[1]  ==> countTramos(s) == s[0] + countTramos(s[1..])
ensures s != [] && s[0] < s[1]  ==> countTramos(s) == countTramos(s[1..])
{
    if s == [] then 0 
    else if s != [] && s[0] >= s[1] then s[0] + countTramos(s[1..]) 
    else countTramos(s[1..])
}

method resuelve(v: array<int>) returns (maxTramos : int)
requires v.Length > 0
ensures forall k:: 0 <= k < v.Length - 1 ==> maxTramos == countTramos(v[..])

Coste O(n)
*/
int resuelve(const std::vector<int> &v) {
    
    int maxTramos = 1;
    int tramoActual = 1;
    
    for (int i = 0; i < v.size() - 1; ++i)
    //invariant 0 <= i <= v.Length
    //decreases v.Length - i
    {
        if (v[i] >= v[i + 1]) {
            ++tramoActual;
            if (maxTramos < tramoActual)
                maxTramos = tramoActual;
        } else
            tramoActual = 1;
    }
    
    return maxTramos;
}

void resuelveCaso() {
    int n;
    std::cin >> n;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    std::cout << resuelve(v) << "\n";
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
