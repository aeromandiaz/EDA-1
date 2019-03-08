//
//  Lista_Extendida.h
//  ProblemasEDA
//
//  Created by Mauri on 01/03/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef ListaExtendida_h
#define ListaExtendida_h

#include <iostream>
#include "list_eda.h"


template <class T>
class ListaExtendida : public list<T> {
	using Nodo = typename list<T>::Nodo;

public:

	template <class Predicate>
	void remove_if(Predicate pred) {
		if (this->nelems == 0)
			return;

		Nodo *aux = this->fantasma->sig, *tmp;
		while (aux != this->fantasma) {
			if (!pred(aux->elem)) {
				if (aux->ant == this->fantasma) {
					this->pop_front();
					aux = this->fantasma->sig;
				}
				else if (aux->sig == this->fantasma) {
					aux->ant->sig = this->fantasma;
					this->fantasma->ant = aux->ant;
					tmp = aux->sig;
					delete aux;
					aux = tmp;
					this->nelems--;
				}
				else {
					aux->ant->sig = aux->sig;
					aux->sig->ant = aux->ant;
					tmp = aux->sig;
					delete aux;
					aux = tmp;
					this->nelems--;
				}
			}
			else
				aux = aux->sig;
		}
	}

};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaExtendida<T> & data) {

	for (size_t i = 0; i < data.size(); i++) {
		T temp = data.front();
		o << temp << "\n";;
		data.push_back(temp);
		data.pop_front();
	}

	return o;
}


#endif /* ListaExtendida_h */
