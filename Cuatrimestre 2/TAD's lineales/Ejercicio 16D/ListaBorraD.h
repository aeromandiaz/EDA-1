//
//  ListaBorraD.h
//  ProblemasEDA
//
//  Created by Mauri on 26/03/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef ListaMerge_h
#define ListaMerge_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class ListaBorraD : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:

	void borrar() {
		Nodo * actual = this->prim;

		T elemAc = actual->elem;

		while (actual != nullptr && actual->sig != nullptr) {
			if (elemAc < actual->elem)
				elemAc = actual->elem;
			if (actual->sig->elem < elemAc) {
				Nodo *tmp = actual->sig;
				actual->sig = tmp->sig;
				if (actual->sig == nullptr)
					this->ult = actual->sig;
				delete tmp;
				this->nelems--;
			} else
				actual = actual->sig;
		}
	}

};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaBorraD<T> & data) {

	for (size_t i = 0; i < data.size(); i++) {
		T temp = data.front();
		o << temp << " ";
		data.push(temp);
		data.pop();
	}

	return o;
}


#endif /* ListaBorraD_h */
