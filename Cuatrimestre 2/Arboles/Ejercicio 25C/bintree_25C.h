//
//  bintree_25C.h
//  ProblemasEDA
//
//  Created by Mauri on 28/03/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef bintree_25C_h
#define bintree_25C_h

#include <iostream>
#include <algorithm>
#include <string>
#include "bintree_eda.h"

struct tSol {
	int numDragones;
	std::string nombre;
};

class bintreePlus : public bintree<std::string> {
	using Link = typename bintree<std::string>::Link;

public:

	bintreePlus() : bintree<std::string>() {}

	bintreePlus(bintreePlus const& l, std::string const& e, bintreePlus const& r) : bintree<std::string>(l, e, r) {}

	tSol dragones() {
		return dragones(this->raiz);
	}

private:

	tSol dragones(Link r) {
		if (r->left == nullptr && r->right == nullptr) {
			if (r->elem == "Dragon") return { 1, "Dragon" };
			else return { 0, r->elem };
		} else if (r->left != nullptr && r->right == nullptr) {
			tSol iz = dragones(r->left);
			if (r->elem == "Dragon") iz.numDragones++;
			else if (r->elem[0] == 'P' || r->elem[0] == 'p') iz.nombre = r->elem;
			return iz;
		} else if (r->left == nullptr && r->right != nullptr) {
			tSol dr = dragones(r->right);
			if (r->elem == "Dragon") dr.numDragones++;
			else if (r->elem[0] == 'P' || r->elem[0] == 'p') dr.nombre = r->elem;
			return dr;
		} else {
			tSol iz = dragones(r->left);
			tSol dr = dragones(r->right);
			tSol sol;

			if (iz.numDragones <= dr.numDragones) {
				sol.numDragones = iz.numDragones;
				sol.nombre = iz.nombre;
			} else {
				sol.numDragones = dr.numDragones;
				sol.nombre = dr.nombre;
			}

			if (r->elem == "Dragon") sol.numDragones++;
			else if (r->elem[0] == 'P' || r->elem[0] == 'p') sol.nombre = r->elem;

			return sol;
		}
	}
};

inline bintreePlus leerArbolPlus(std::string vacio) {
	std::string raiz;
	std::cin >> raiz;
	if (raiz == vacio) {
		return {};
	}
	else {
		auto iz = leerArbolPlus(vacio);
		auto dr = leerArbolPlus(vacio);
		return { iz, raiz, dr };
	}
}


#endif /* bintree_25C_h */
