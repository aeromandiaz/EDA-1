#include <iostream>
#include <fstream>
#include <vector>

struct tSol {
    int anchuraPrimerEscalon;
    int anchuraUltimoEscalon;
    int anchuraMasAncho;
};

/*
           | c0 si n = 1
    T(n) = |
           | 2T(n/2) + c1 si n > 1
 
 Despliegue: T(n) = 2T(n/2) + c1 = 2(2T(n/2^2) + c1) + c1 = 2^2T(n/2^2) + c1 + c1=
 2^2(2T(n/2^3) + c1) + 2c1 = 2^3T(n/2^3) + 3c1 = ... = 2^k(T(n/2^k) + kc1 =
 2^log(n)T(1) + log(n) * c1
 
 n/2^k = 1
 n = 2^k
 log(n) = log(2^k)
 log(n) = k
 */
//Coste O(n)
tSol dyv(const std::vector<int> &v, const int &ini, const int &fin) {
    
    if (ini + 1 == fin) //Si el vector es de un elemento
        return {1, 1, 1};
    
    if (v[ini] == v[fin - 1]) return {fin - ini, fin - ini, fin - ini}; //Si todos los elementos del vector son iguales.
    
    int m = (ini + fin - 1) / 2;
    tSol dr, iz;
    
    iz = dyv(v, ini, m + 1);
    dr = dyv(v, m + 1, fin);
    
    tSol sol = {iz.anchuraPrimerEscalon, dr.anchuraUltimoEscalon, std::max(iz.anchuraMasAncho, dr.anchuraMasAncho)};
    //Cojo el tam del primer escalon de la izquierda, el tam del ultimo escalon por la derecha e inicializo a 1 el mayor de todos.
    
    if (m > 0 && m < fin && v[m-1] == v[m+1]) //Si el justo anterior de la mitad y el justo siguiente son iguales sumo la anchura del último escalón de la izquierda y le sumo la anchura del primer escalón de la derecha.
        sol.anchuraMasAncho = iz.anchuraUltimoEscalon + dr.anchuraPrimerEscalon;
    else {
        if (m > 0 && v[m-1] == v[m]) //Si el elemento del medio y el justo anterior son iguales, cojo el maximo del izquierdo
            sol.anchuraMasAncho = iz.anchuraMasAncho;
        else if (m < fin - 1 && v[m+1] == v[m])//Si el elemento del medio y el justo siguiente son iguales, cojo el maximo de la derecha y le sumo 1 (añado el del elemento del medio).
            sol.anchuraMasAncho = dr.anchuraMasAncho + 1;
    }
    
    if (v[m + 1] == v[ini] && m != ini) //Si el primero y el del medio son iguales, añado uno del primero
        ++sol.anchuraPrimerEscalon;
    else if (v[m] == v[fin - 1] && m != fin - 1) //Si el último y el del medio son iguales, añado uno del último
        ++sol.anchuraUltimoEscalon;
    
    return sol;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if (n == 0) return false;
    
    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    tSol sol = dyv(v, 0, n);
    std::cout << sol.anchuraPrimerEscalon << " " << sol.anchuraUltimoEscalon << " " << sol.anchuraMasAncho << "\n";
    
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
