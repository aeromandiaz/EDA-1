//Ejercicio 30
//Mauricio Abbati Loureiro - EDA 2ºE 2018/2019
//E01
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <list>

using diccionario = std::map<std::string, int>;

void resolver(const diccionario &viejo, const diccionario &nuevo) {
    auto it = viejo.cbegin();
    auto it2 = nuevo.cbegin();
    std::list<std::string>nuevos, eliminados, cambiados;
    
    while (it != viejo.cend() || it2 != nuevo.cend()) {
        if (it != viejo.cend() && it2 != nuevo.cend() && it->first == it2->first) {
            if (it->second != it2->second) cambiados.push_back(it->first);
            ++it; ++it2;
        }
        else if (it2 != nuevo.cend() && it != viejo.cend() && it->first > it2->first) {
            nuevos.push_back(it2->first);
            ++it2;
        }
        else if (it != viejo.cend() && it2 != nuevo.cend() && it->first < it2->first) {
            eliminados.push_back(it->first);
            ++it;
        }
        else if (it == viejo.cend() && it2 != nuevo.cend()) {
            nuevos.push_back(it2->first);
            ++it2;
        }
        else if (it != viejo.cend() && it2 == nuevo.cend()) {
            eliminados.push_back(it->first);
            ++it;
        }
        
    }
    
    if (nuevos.size() == 0 && eliminados.size() == 0 && cambiados.size() == 0)
        std::cout << "Sin cambios\n";
    else {
        if (nuevos.size() != 0){
            std::cout << "+";
            for (auto &n : nuevos)
                std::cout << " " << n;
        }
        
        if (eliminados.size() != 0){
            std::cout << "\n" << "-";
            for (auto &e : eliminados)
                std::cout << " " << e;
        }
        
        if (cambiados.size() != 0){
            std::cout << "\n" << "*";
            for (auto &m : cambiados)
                std::cout << " " << m;
        }
        std::cout << "\n";
    }
}
void resuelveCaso() {
    
    diccionario viejo, nuevo;
    std::string clave;
    
    int valor;
    std::string linea;
    getline(std::cin, linea);
    
    std::stringstream v(linea);
    while (v >> clave >> valor)
        viejo[clave] = valor;
    
    getline(std::cin, linea);
    std::stringstream n(linea);
    
    while (n >> clave >> valor)
        nuevo[clave] = valor;
    
    resolver(viejo,nuevo);
    
    std::cout << "----\n";
}

int main() {
    
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    int n;
    std::cin >> n;
    std::cin.ignore();
    
    for (int i = 0; i < n; ++i)
        resuelveCaso();
     
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
}
