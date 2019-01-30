//Ejercicio 44
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

struct tSol {
    int secMasLarga;
    int numLlanos;
    std::vector<int> vSol;
};

tSol resolver(std::vector<int> const& v, const int &iguales) {
    
    tSol sol = {0, 0, std::vector<int>(v.size()/iguales, - 1)};
    
    int maximo = v[v.size() - 1], longitud = 0;
    
    for(int i = v.size() - 1; i > -1; --i) {
        
        if(v[i] >= maximo) {
            if(v[i] > maximo) {
                longitud = 1;
                maximo = v[i];
            } else {
                ++longitud;
                if(longitud >= iguales) {
                    if(longitud == iguales)
                        sol.vSol[sol.numLlanos++] = i + (longitud - 1);
                    if(longitud > sol.secMasLarga)
                        sol.secMasLarga = longitud;
                }
            }
        } else
            longitud = 0;
    }
    
    return sol;
}

bool resuelveCaso() {
    
    int n, l;
    std::cin >> n >> l;
    
    if (!std::cin) return false;
    
    std::vector<int>v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    
    tSol sol = resolver(v,l);
    
    std::cout << sol.secMasLarga << " " << sol.numLlanos;
    
    for (int i = 0; i < sol.vSol.size() && sol.vSol[i] != -1; ++i)
        std::cout << " " << sol.vSol[i];
    
    std::cout << "\n";
    
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
