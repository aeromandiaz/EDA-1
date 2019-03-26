//
//  ListaBorraPar.h
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
class ListaBorraPar : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:

	void borrar() {
		Nodo * actual = this->prim;

		while (actual != nullptr && actual->sig != nullptr) {
			Nodo *tmp = actual->sig;
			actual->sig = tmp->sig;
			if (actual->sig == nullptr)
				this->ult = actual->sig;
			delete tmp;
			actual = actual->sig;
			this->nelems--;
		}
	}

};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaBorraPar<T> & data) {

	for (size_t i = 0; i < data.size(); i++) {
		T temp = data.front();
		o << temp << " ";
		data.push(temp);
		data.pop();
	}

	return o;
}


#endif /* ListaBorraPar_h */
