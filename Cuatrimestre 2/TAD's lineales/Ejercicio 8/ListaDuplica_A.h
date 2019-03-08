//
//  ListaDuplica.h
//  ProblemasEDA
//
//  Created by Mauri on 15/02/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef ListaDuplica_h
#define ListaDuplica_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class ListaDuplica : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:

	void duplicar() {
		Nodo * aux = this->prim;

		while (aux != nullptr) {
			Nodo *nuevo = new Nodo(aux->elem, aux->sig);
			if (nuevo->sig == nullptr)
				this->ult = nuevo;
			aux->sig = nuevo;
			aux = aux->sig->sig;
		}

		this->nelems = this->nelems * 2;
	}

	void anhadeFinal(ListaDuplica<T> &listaNueva) {
		Nodo * nodoActual = this->ult;

		if (this->nelems == 0) {
			/*if (nodoActual->sig == nullptr)
				this->ult = nodoActual;*/
			//listaNueva.ult->sig = nodoActual;
			this->prim = listaNueva.prim;
			this->ult = listaNueva.ult;
		}
		else {
			nodoActual->sig = listaNueva.prim;
			this->ult = listaNueva.ult;
		}

		this->nelems = this->nelems + listaNueva.size();
		listaNueva.nelems = 0;
		listaNueva.prim = nullptr;
		listaNueva.ult = nullptr;
	}

	void eliminaIni(const int &cant) {
		Nodo * nodoActual = this->prim;

		for (int i = 0; i < cant; ++i) {
			this->prim = this->prim->sig;
			delete nodoActual;
			nodoActual = this->prim;
		}

		if (this->prim->sig == nullptr)
			this->ult = this->prim;

		this->nelems = this->nelems - cant;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaDuplica<T> & data) {

	for (size_t i = 0; i < data.size(); i++) {
		int temp = data.front();
		o << temp << " ";
		data.push(temp);
		data.pop();
	}

	return o;
}


#endif /* ListaDuplica_h */
