//Ejercicio 39
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

void resuelveCaso() {
    
    int n, t, pos = 0, posMax = 0, contador = 0, contMax = 0, ultimo = 0;
    
    std::cin >> n >> t;

    for (int i = 0; i < n; ++i) {
        int elem;
        std::cin >> elem;
        if (elem > t) {
            ++contador;
            if (contador == 1)
                pos = i;
            if (contador > contMax) {
                contMax = contador;
                posMax = pos;
                ultimo = i;
            }
        } else
            contador = 0;
    }
    
    std::cout << posMax << " " << ultimo << "\n";
    
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
    
    for (int i = 0; i < n; ++i)
        resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}
