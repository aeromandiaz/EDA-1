//
//  InvierteLista.h
//  ProblemasEDA
//
//  Created by Mauri on 19/02/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef InvierteLista_h
#define InvierteLista_h

#include <iostream>
#include "deque_eda.h"

template <class T>
class InvierteLista : public deque<T> {
	using Nodo = typename deque<T>::Nodo;

public:

	void invierte() {
		Nodo *actual = this->fantasma->sig, * ant = actual->sig, *sig = this->fantasma;
		
		for (int i = 0; i < this->nelems; ++i) {
			actual->ant = ant;
			actual->sig = sig;
			sig = actual;
			ant = ant->sig;
			actual = sig->ant;
		}
		Nodo *tmp = this->fantasma->ant;
		this->fantasma->ant = this->fantasma->sig;
		this->fantasma->sig = tmp;
	}

};

template <class T>
inline std::ostream& operator<<(std::ostream & o, InvierteLista<T> & data) {

	for (size_t i = 0; i < data.size(); i++) {
		int temp = data.front();
		o << temp << " ";
		data.push_back(temp);
		data.pop_front();
	}

	return o;
}


#endif /* InvierteLista_h */
