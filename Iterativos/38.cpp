//Ejercicio 38
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

void resuelveCaso() {
    
    int vagones, tiempo, resultado = 0, resultadoMax = 0, pos = 0;
    
    std::cin >> vagones >> tiempo;

    std::vector<int>jajadineroDINERO(vagones);
    
    for (int i = 0; i < vagones; ++i)
        std::cin >> jajadineroDINERO[i];
    
    for (int i = 0; i < tiempo; ++i)
        resultado += jajadineroDINERO[i];
    
    resultadoMax = resultado;
    
    for (int i = 0; i < vagones - tiempo; ++i) {
        resultado += jajadineroDINERO[i + tiempo] - jajadineroDINERO[i];
        if (resultado >= resultadoMax) {
            resultadoMax = resultado;
            pos = i + 1;
        }
    }
    std::cout << pos << " " << resultadoMax << "\n";
    
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
