//Ejercicio 26
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct tJuguete {
    int uds;
    std::string tipo;
};

using tMatriz = std::vector<std::vector<int>>;

std::ostream& operator << (std::ostream &o, const std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        o << v[i];
        if (i + 1 == v.size())
            o << "\n";
        else
            o << " ";
    }
    return o;
}

bool esValida(const std::vector<int> &sol, const int &k, const int &i, const std::vector<tJuguete> &v, const tMatriz &mat, const int &maxSat){
    
    if (k > 0 && k % 2 != 0 && (mat[k / 2][sol[k - 1]] + mat[k / 2][sol[k]] < maxSat)) return false;
    if (v[i].uds < 0) return false;
    if (k > 0 && k % 2 != 0 && (v[i].tipo == v[sol[k - 1]].tipo)) return false;
    if (k > 0 && k % 2 != 0 && (sol[k] < sol[k - 1])) return false;
    
    return true;
}

void vueltaAtras(std::vector<int> &sol, const int &k, std::vector<tJuguete> &v, const tMatriz &mat, const int &maxSat, bool &haySol){
   
    for (int i = 0; i < v.size(); ++i) {
        sol[k] = i;
        v[i].uds--;
        if (esValida(sol, k, i, v, mat, maxSat)) {
            if (k + 1 == sol.size()) {
                std::cout << sol;
                haySol = true;
            } else {
                vueltaAtras(sol, k + 1, v, mat, maxSat, haySol);
            }
        }
        v[i].uds++;
    }
}


bool resuelveCaso() {
    int n, m, satisfaccion;
    std::cin >> m >> n >> satisfaccion;
    
    if(!std::cin) return false;
    
    std::vector<tJuguete> v(m);
    tMatriz mat(n, std::vector<int>(m));
    
    for (int i = 0 ; i < m; ++i)
        std::cin >> v[i].uds;
    for (int i = 0 ; i < m; ++i)
        std::cin >> v[i].tipo;
    
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < m; ++c) {
            std::cin >> mat[i][c];
        }
    }
    
    std::vector<int> sol(n * 2);
    bool haySol = false;
    
    vueltaAtras(sol, 0, v, mat, satisfaccion, haySol);
    
    if (!haySol)
        std::cout << "SIN SOLUCION\n";
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

    while ( resuelveCaso());
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}
