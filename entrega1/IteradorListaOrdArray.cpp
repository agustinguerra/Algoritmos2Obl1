#ifndef ITERADORLISTAORDIMPARRAY_CPP
#define ITERADORLISTAORDIMPARRAY_CPP

#include "ListaOrdImpArray.h"
#include "IteradorListaOrdArray.h"
#include "Puntero.h"
#include <iostream>
#include <assert.h>
#include <typeinfo.h>


//Poscondicion: construye el iterador a la ListaOrdArray
template <class T>
IteradorListaOrdArray<T>::IteradorListaOrdArray(const Array<T>& iterable, int tamano, int posicion) {
	this->arrayDeLista = iterable;
	this->tamano = tamano;
	this->posicion = posicion;
	this->inicio = posicion;
}
//Poscondicion: devuelve true si la ListaOrdArray tiene algun elemento. False en el caso contrario
template <class T>
bool IteradorListaOrdArray<T>::HayElemento() const {
	if (this->posicion > 0) {
		return true;
	}
	else {
		return false;
	}
}
//Precondicion: La ListaOrdArray no esta vacia
//Poscondicion: devuelve el dato en la posicion actual
template <class T>
const T& IteradorListaOrdArray<T>::ElementoActual() const {
	return this->arrayDeLista[posicion];
}
//Precondicion: La ListaOrdArray no esta vacia
//Poscondicion: avanza en la ListaOrdArray
template <class T>
void IteradorListaOrdArray<T>::Avanzar() {
	this->posicion = this->posicion - 1;
}
//Poscondicion: Reinicia el iterador a la posicion primera
template <class T>
void IteradorListaOrdArray<T>::Reiniciar() {
	this->posicion = this->inicio;
}
//Poscondicion: clona el iterador
template <class T>
Puntero<Iteracion<T>> IteradorListaOrdArray<T>::Clonar() const {
	Iteracion<T>* t = new IteradorListaOrdArray(*this);
	return Puntero<Iteracion<T>>(t);
}


#endif