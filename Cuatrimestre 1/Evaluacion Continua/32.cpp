
//*****************
// IMPORTANTE
//
// Mauricio Abbati Loureiro
// E01
// E01
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


//*******************************
// Aqui explicacion del algoritmo de vuelta atras. Como es el vector solucion y como se obtiene
//
//
//*******************************

template <class T>
using tMatriz = std::vector<std::vector<T>>;

struct tDatos {
	int numCiudades;
	int comienzoTemporadaBaja;
	int presupuesto;
	std::vector<int> hotelesBaja; // precio de los hoteles en temporada baja
	std::vector<int> hotelesAlta; // Precio de los hoteles en temporada alta
	tMatriz<int> billetes;  // precio de los billetes entre cada par de ciudades
};

// Aqui las funciones implementadas por el alumno

bool esValida(const tDatos &datos, const int &precioAcumulado, const int &mejorSolucion) {

	//if (aux[k] == 0) return false;
	if (precioAcumulado > datos.presupuesto) return false;
    if (precioAcumulado > mejorSolucion) return false;

	return true;
}


void vueltaAtras(const tDatos &datos, std::vector<int> &aux, std::vector<bool> &marcas, const int &k,
	bool &haySol, int precioAcumulado, int &mejorSolucion) {

	for (int i = 0; i < datos.numCiudades; ++i) {
		if (!marcas[i]) {
			//aux[k] = datos.billetes[k][i];
			aux[k] = i + 1;
			precioAcumulado += datos.billetes[aux[k - 1]][i + 1];
			if ( k  >= datos.comienzoTemporadaBaja) {
				precioAcumulado += datos.hotelesBaja[i];
			}
			else {
				precioAcumulado += datos.hotelesAlta[i];
			}
			if (esValida(datos, precioAcumulado, mejorSolucion)) {
				if (k == datos.numCiudades) { //Es solución.
					if (precioAcumulado + datos.billetes[i + 1][0] < mejorSolucion) { //Es mejor solución.
						mejorSolucion = precioAcumulado + datos.billetes[i + 1][0];
						haySol = true;
						//for (int z = 0; z < aux.size(); ++z) vectorSolucion[z] = aux[z];
					}
				}
				else {
					marcas[i] = true;
					vueltaAtras(datos, aux, marcas, k + 1, haySol,
						precioAcumulado, mejorSolucion);
					marcas[i] = false;
				}
			}
			precioAcumulado -= datos.billetes[aux[k - 1]][i + 1];
			if ( k  >= datos.comienzoTemporadaBaja)
				precioAcumulado -= datos.hotelesBaja[i];
			else
				precioAcumulado -= datos.hotelesAlta[i];
		}
	}
}


bool resuelveCaso() {
	tDatos d;
	std::cin >> d.numCiudades >> d.comienzoTemporadaBaja >> d.presupuesto;
	if (d.numCiudades == 0) return false;
	// precio hoteles temporada alta
	// Guarda en la posicion 0 el hotel de la ciudad 1.
	d.hotelesAlta.resize(d.numCiudades);
	for (int &n : d.hotelesAlta) std::cin >> n;
	// precio hoteles temporada baja. 
	// Guarda en la posicion 0 el hotel de la ciudad 1.
	d.hotelesBaja.resize(d.numCiudades);
	for (int &n : d.hotelesBaja) std::cin >> n;
	// Precio billetes entre ciudades. La ciudad 0 es la ciudad de origen
	d.billetes.resize(d.numCiudades + 1, std::vector<int>(d.numCiudades + 1));
    for (int i = 0; i <= d.numCiudades; ++i) {
		for (int j = 0; j <= d.numCiudades; ++j)
			std::cin >> d.billetes[i][j];
    }

	// Preparacion de los datos para la llamada a la funcion que resuelve el problema

	std::vector<bool> marcas(d.numCiudades + 1, false);
	bool haySol = false;
	std::vector<int> sol(d.billetes.size());
	int mejorSolucion = d.presupuesto + 1;
	/*sol[0] = 0;
	marcas[0] = true;*/

	// LLamada a la funcion que resuelve el problema

	vueltaAtras(d, sol, marcas, 1, haySol, 0, mejorSolucion);

	// Escribir el resultado
	if (!haySol) std::cout << "No puedes ir\n";
	else {
		std::cout << mejorSolucion << "\n";
		/*for (int i = 0; i < solMejor.size(); ++i) {
			std::cout << solMejor[i] << " ";
		}
		std::cout << "\n";*/
	}

		return true;
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

	// Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
