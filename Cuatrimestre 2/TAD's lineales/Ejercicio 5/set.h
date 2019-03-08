//
//  set.h
//  ProblemasEDA
//
//  Created by Mauri on 09/02/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//


#ifndef set_h
#define set_h

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <utility>

template <class T>
class set {
	size_t contador;
	size_t capacidad;
	T * datos;
	int contains(int ini, int fin, T elem) const;
	T getMinor() const;
	void eraseMinor();

public:
	set() : contador(0), capacidad(8), datos(new T[capacidad]) {};

	set(const int &MAX) : contador(0), capacidad(MAX), datos(new T[MAX+1]) {};

	~set() { delete[] datos; };

	void insert(T e);

	bool empty() const { return contador == 0; };

	T getValue(const int &index) const { return datos[index]; }

	size_t size() const { return contador; };
};


template <class T>
void set<T>::insert(T e) {
	if (contains(0, contador, e) == -1) {
		datos[contador] = e;
		++contador;
		if (contador > 1) {
			int i, j;
			T aux;
			for (i = 1; i < contador; i++) {
				aux = datos[i];
				j = i;

				while (j > 0 && datos[j - 1] < aux) {
					datos[j] = datos[j - 1];
					--j;
				}
				datos[j] = aux;
			}
			if (contador > capacidad)
				eraseMinor();
		}
	}
}

template <class T>
T set<T>::getMinor() const {
	if (empty())
		throw std::domain_error("ERROR! Lista vacia.");
	
	return datos[contador];
}

template <class T>
int set<T>::contains(int ini, int fin, T elem) const {
	if (empty()) return -1;
	if (ini + 1 == fin) {
		if (datos[ini] == elem) return ini;
		else return -1;
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (datos[m] == elem) return true;
		else if (datos[m] < elem) return contains(ini, m + 1, elem);
		else return contains(m + 1, fin, elem);
	}
}

template <class T>
void set<T>::eraseMinor() {
	if (contador > 0)
		--contador;
	else
		throw std::domain_error("ERROR! Lista vacia.");
}

template <class T>
inline std::ostream& operator <<(std::ostream &out, set<T> const& aux) {

	for (int i = aux.size() - 1; i >= 0; --i) {
		out << aux.getValue(i);
		if (i > 0) out << " ";
	}

	return out;
}

#endif /* set_h */
