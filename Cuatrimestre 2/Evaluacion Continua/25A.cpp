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
#include <algorithm>
#include "bintree_eda.h"


// COSTE DE LA FUNCION RESUELVE
/*
	Caso del equilibrado
			| c0 si n == 0.
	T(n) =  |
			| 2(T(n)/2) + c0  n > 0.

	Coste: O(n) siendo n el numero de nodos del arbolito.

	Caso del degenerado
			| c0 si n == 0.
	T(n) =  |
			| T(n - 1) + c0  n > 0.

	Coste: O(n) siendo n el numero de nodos del arbolito.

*/

struct tSol {
	bool esGenealogico;
	int prof;
};

tSol resuelve(const bintree<int> &arbol) {
	if (arbol.empty()) //Si es vacio entonces esGenealogico y su numero de generaciones es 0.
		return { true, 0 };

	//Si no es vacio miro a mis dos hijos para ver si ellos cumplen las condiciones del problema.
	tSol izq = resuelve(arbol.left());
	tSol dr = resuelve(arbol.right());

	tSol sol;
	sol.prof = std::max(izq.prof, dr.prof) + 1; //Aquí calculo el número de generaciones.
	sol.esGenealogico = izq.esGenealogico && dr.esGenealogico;

	if (sol.esGenealogico) {
		//Si el padre no supera en 18 en edad al hijo izquierdo entonces el arbol no es genealogico.
		if (!arbol.left().empty() && arbol.root() - 18 < arbol.left().root())
			sol.esGenealogico = false;
		//Si el padre no supera en 18 en edad al hijo derecho entonces el arbol no es genealogico.
		else if (!arbol.right().empty() && arbol.root() - 18 < arbol.right().root())
			sol.esGenealogico = false;
		//Si no hay hijo izquierdo pero si hijo derecho entonces el arbol no es genealogico.
		else if (arbol.left().empty() && !arbol.right().empty())
			sol.esGenealogico = false;
		//Si hay hijo izquierdo y derecho pero el izquierdo no supera en 2 años al menos al derecho no es genealogico.
		else if (!arbol.left().empty() && !arbol.right().empty() &&
			arbol.left().root() - 2 < arbol.right().root())
			sol.esGenealogico = false;
	}

	return sol;
}


void resuelveCaso() {
    bintree<int> tree = leerArbol(-1);

	tSol sol = resuelve(tree);

	if (!sol.esGenealogico) std::cout << "NO\n";
	else std::cout << "SI " << sol.prof << "\n";

}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //redirect std::cin to casos.txt
#endif

    int numCasos; std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {resuelveCaso();}
    
    // Para restablecer entrada. 
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
