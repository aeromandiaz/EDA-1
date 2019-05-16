//*****************
// IMPORTANTE
//
// Mauricio Abbati Loureiro
// Manuel Guerrero Moñús.
// E01 / E24
// E01
//
//***************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using pelis = std::string;
using dias = std::string;
// Declarar las librerias que se utilicen en el codigo

//La clave es el numero de veces repetidas.
//El valor es un mapa ordenado por la clave, que son las pelis, y un vector que contiene las fechas
// de emisión.
using Mapa1 = std::map<int, std::map<pelis, std::vector<dias>>, std::greater<int>>;

//COSTE O(n), siendo n el numero de fechas de la película más repetida (ya podían comprar nuevas!).

bool resuelveCaso() {
    int numDias; 
    std::cin >> numDias;
    if (!std::cin) return false;
    
    // Declaracion de estructuras de datos
	Mapa1 top;
	std::map<pelis, int> numVeces;


    // Bucle de lectura de datos
    for (int i = 0; i < numDias; ++i) {
		dias fecha;
		pelis titulo; 
		int numPeliculas;
        std::cin >> fecha >> numPeliculas;
        std::cin.ignore();
        // Bucle de lectura de las peliculas de cada dia
        for (int i = 0; i < numPeliculas; ++i) {
            getline(std::cin, titulo);

			//Coste (Log n)
			if (numVeces.count(titulo) == 0) { //Miramos si la peli se había emitido alguna vez.
				numVeces[titulo] = 1;
				top[numVeces[titulo]][titulo].push_back(fecha); //Metemos la primera fecha.
			}
			else {
				//Coste (Log n)
				int aux = numVeces[titulo]; //Lo guardamos para más tarde
				numVeces[titulo]++; //Esta peli ahora aparece una vez más
				std::vector<dias> fechasPelis = top[aux][titulo];
				if (fechasPelis[fechasPelis.size() - 1] != fecha)
					fechasPelis.push_back(fecha); //Si la fecha anterior no es igual que la de ahora la ponemos
				top[aux].erase(titulo); //Borramos esta peli de la categoria anterior.
				top[numVeces[titulo]][titulo] = fechasPelis; //Metemos el vector en la categoria nueva.
			}
        }
    }

	std::cout << (*top.cbegin()).first << "\n";

	for (const auto &it : (*top.cbegin()).second) {
		std::cout << it.first ;
		//Coste O(n) siendo n el numero de fechas de la película más repetida.
		for (const auto &it2 : it.second)
			std::cout << " " << it2;
		std::cout << "\n";
	}

    // Marca de final de caso
    std::cout << "---\n";
    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos
   
    // Para restablecer entrada. 
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
