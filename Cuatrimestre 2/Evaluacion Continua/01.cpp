//*****************
// IMPORTANTE
//
// Mauricio Abbati Loureiro
// Manuel Guerrero Moñús
// E01 y E24
// E01
//
//***************************************************

#include <iostream>
#include <fstream>
#include "queue_eda.h"


template <typename T>
class listaPlus: public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    // Metodo que intercambia los elementos de la lista dos a dos
    void modifica() {
        // Aqui el codigo del alumno
		Nodo *act = this->prim;
		Nodo *aux1 = act->sig;
		Nodo *aux2 = nullptr;

		if (aux1 != nullptr) {
			aux2 = aux1->sig;
			this->prim->sig = aux2;
			aux1->sig = act;
			this->prim = aux1;
			if (aux2 == nullptr)
				this->ult = act;
			act = aux1->sig;
			aux1 = aux2;
		}

		while (aux1 != nullptr && aux1->sig != nullptr) {
			aux2 = aux1->sig;
			Nodo *tmp = aux2->sig;
			aux2->sig = aux1;
			aux1->sig = tmp;
			act->sig = aux2;
			act = aux1;
			aux1 = tmp;
			if (tmp == nullptr) 
				this->ult = act;
		}
        
    }
    
    // Escribir los elementos de la lista
	void print() const {
		// Aqui codigo del alumno
		Nodo *aux = this->prim;

		std::cout << "PRIM: " << aux->elem << "\n";

		while (aux != nullptr) {
			std::cout << aux->elem;
			aux = aux->sig;
			if (aux != nullptr)
				std::cout << " ";
		}


		std::cout << " ULT: " << this->ult->elem << "\n";

		std::cout << "\n";
	}
        
    };



bool resuelveCaso() {
    // Lectura de datos
    int numElem;
    std::cin >> numElem;
    if (numElem == 0) return false;
    listaPlus<int> l;
    for (int i = 0; i < numElem; ++i) {
        int p; std::cin >> p;
        l.push(p);
    }
    // Modificar la lista
    l.modifica();
    // Salida de datos
    l.print();
    return true;
}



int main() {
    // Para la entrada por fichero.
 #ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //redirect std::cin to casos.txt
#endif

    while (resuelveCaso()){  //Resolvemos todos los casos
        ;
    }

    
    // Para restablecer entrada. 

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
