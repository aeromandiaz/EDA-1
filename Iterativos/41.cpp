//Ejercicio 41
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>

enum piedrasPreciosas {diamante, rubi, esmeralda, zafiro, jade};

std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
    char num;
    entrada >>  num;
    switch (num) {
        case 'd': p = diamante; break;
        case 'r': p = rubi; break;
        case 'e': p = esmeralda; break;
        case 'z': p = zafiro; break;
        case 'j': p = jade; break;
    }
    return entrada;
}

int resolver(std::vector<piedrasPreciosas> const& v, const int &tamSec, const piedrasPreciosas &t1, const piedrasPreciosas &t2, const int &numT1, const int &numT2) {
    
    int secuencias = 0, primera = 0, segunda = 0;
    
    for (int i = 0; i < tamSec; ++i) {
        if (v[i] == t1)
            ++primera;
        else if (v[i] == t2)
            ++segunda;
    }
    
    if (numT1 <= primera && numT2 <= segunda)
        ++secuencias;
    
    for (int i = tamSec; i < v.size(); ++i) {
        if (v[i] == t1)
            ++primera;
        else if (v[i] == t2)
            ++segunda;
        if (v[i - tamSec] == t1)
            --primera;
        else if (v[i - tamSec] == t2)
            --segunda;
        if (numT1 <= primera && numT2 <= segunda)
            ++secuencias;
    }
    
    return secuencias;
}

void resuelveCaso() {
    
    int numpiedras, tamSec;
    int numtipo1, numtipo2;
    piedrasPreciosas tipo1, tipo2;
    std::cin >> numpiedras >> tamSec >> tipo1 >> numtipo1 >> tipo2 >> numtipo2;
    
    std::vector<piedrasPreciosas> v(numpiedras);
    for (piedrasPreciosas& i : v) std::cin >>  i;
    
    
    std::cout << resolver(v, tamSec, tipo1, tipo2, numtipo1, numtipo2) << "\n";
    
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

    for(int i = 0;i < n; ++i)
        resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}
