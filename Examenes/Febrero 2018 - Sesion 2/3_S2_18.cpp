#include <iostream>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

bool esValida(int k, const std::vector<int> &quitanieves, const std::vector<bool> &marcasCarret, int i, const std::vector<int> &anchoCarret) {
    
    if (marcasCarret[i]) return false;
    if (anchoCarret[i] < quitanieves[k]) return false;
    
    return true;
}

/*
 K es nuestra Mr. Quitanieves
 i será la carretera por la que pasará la Mr. Quitanieves K.
 */
void va(const tMatriz &mat, int k, int m, int n, const std::vector<int> &quitanieves, const std::vector<int> &anchoCarret, int ac, std::vector<bool> &marcasCarret, int &mejorSol) {
    
    for (int i = 0; i < n; ++i) {
        ac += mat[k][i];
        if (esValida(k, quitanieves, marcasCarret, i, anchoCarret)) {
            if (k + 1 == m) { //Es solución
                if (ac >= mejorSol) //Es mejor solución
                    mejorSol = ac;
            }
            else {
                marcasCarret[i] = true;
                va(mat, k + 1, m, n, quitanieves, anchoCarret, ac, marcasCarret, mejorSol);
                marcasCarret[i] = false;
            }
        }
        ac -= mat[k][i];
    }
}

void resuelveCaso() {
    int m, n;
    std::cin >> m >> n;
    
    std::vector<int> mrquitanieves(m), anchuraCarret(n);
    
    for (int i = 0; i < m; ++i)
        std::cin >> mrquitanieves[i];
    
    for (int i = 0; i < n; ++i)
        std::cin >> anchuraCarret[i];
    
    tMatriz mat(m, std::vector<int>(n,0));
    
    for (int f = 0; f < m; ++f) {
        for (int c = 0; c < n; ++c)
            std::cin >> mat[f][c];
    }
    
    int mejorSol = 0;
    int ac = 0;
    std::vector<bool> marcasCarret(n, false);

    va(mat, 0, m, n, mrquitanieves, anchuraCarret, ac, marcasCarret, mejorSol);
    
    std::cout << mejorSol << "\n";
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
