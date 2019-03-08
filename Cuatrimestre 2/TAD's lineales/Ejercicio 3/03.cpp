#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

template <class E>
class Complejo {
private:
	E real;
	E imaginaria;
public:
	Complejo() :
		real(0), imaginaria(0) {}

	Complejo(E r, E i) :
		real(r), imaginaria(i) {}

	Complejo operator + (const Complejo &c) const;
	Complejo operator - (const Complejo &c) const;
	Complejo operator * (const Complejo &c) const;
	E modulo() const {
		E aux;
		aux = sqrt((this->real*this->real) + (this->imaginaria*this->imaginaria));
		return aux;
	}
};

template <class E>
Complejo<E> Complejo<E>::operator + (const Complejo<E> &c) const {
	Complejo aux;
	aux.real = this->real + c.real;
	aux.imaginaria = this->imaginaria + c.imaginaria;
	return aux;
}
template <class E>
Complejo<E> Complejo<E>::operator - (const Complejo<E> &c) const {
	Complejo aux;
	aux.real = this->real - c.real;
	aux.imaginaria = this->imaginaria - c.imaginaria;
	return aux;
}
template <class E>
Complejo<E> Complejo<E>::operator * (const Complejo<E> &c) const {
	Complejo aux;
	aux.real = this->real*c.real - this->imaginaria*c.imaginaria;
	aux.imaginaria = this->real*c.imaginaria + this->imaginaria*c.real;
	return aux;
}

template<class E>
bool evaluarComplejo(const int &vueltas, const float &real, const float &imaginario) {
	bool ok = false;
	int i = 1;
	Complejo<E> aux(0, 0), c(real, imaginario);
	while ((aux.modulo() <= 2) && (i <= vueltas)) {
		aux = (aux*aux) + c;
		++i;
	}
	return (i == vueltas + 1);
}

void resuelveCaso() {

	float real, imag;
	int vueltas;
	std::cin >> real;
	std::cin >> imag >> vueltas;
	Complejo<float> c(real, imag);

	if (evaluarComplejo<float>(vueltas, real, imag)) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int nCasos = 0;
	std::cin >> nCasos;

	for (int i = 0; i < nCasos; ++i) resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif
}