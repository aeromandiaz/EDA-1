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
#include "queue_eda.h"

template <class T>
class InvierteLista : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:

	void invierte() {
		Nodo * ant = nullptr, *actual = this->prim, *sig = nullptr;
		
		while (actual != nullptr) {
			sig = actual->sig;
			actual->sig = ant;
			ant = actual;
			actual = sig;
		}
		Nodo *tmp = this->prim;
		this->prim = this->ult;
		this->ult = tmp;
	}

};

template <class T>
inline std::ostream& operator<<(std::ostream & o, InvierteLista<T> & data) {

	for (size_t i = 0; i < data.size(); i++) {
		int temp = data.front();
		o << temp << " ";
		data.push(temp);
		data.pop();
	}

	return o;
}


#endif /* InvierteLista_h */
