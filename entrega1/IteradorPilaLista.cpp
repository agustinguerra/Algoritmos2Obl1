#ifndef ITERADORPILALISTA_CPP
#define ITERADORPILALISTA_CPP

#include "PilaLista.h"
#include "IteradorPilaLista.h"
#include "Puntero.h"
#include "Puntero.h"
#include <iostream>
#include <assert.h>
#include <typeinfo.h>




//Poscondicion: construye el iterador a la PilaLista
template <class T>
IteradorPilaLista<T>::IteradorPilaLista(const ListaPila<T>& iterable, int tamano, int cantidadActual) {
	//Puntero<ListaPila<T>> aux = iterable;
	this->inicio = iterable;
	this->pilaL = iterable;
}

//Poscondicion: construye el iterador a la PilaLista
template <class T>
IteradorPilaLista<T>::IteradorPilaLista(const Puntero<ListaPila<T>>& iterable) {
	//Puntero<ListaPila<T>> aux = iterable;
	this->inicio = iterable;
	this->pilaL = iterable;
}


//Poscondicion: devuelve true si la PilaLista tiene algun elemento. False en el caso contrario
template <class T>
bool IteradorPilaLista<T>::HayElemento() const {
	return this->pilaL != NULL;
}

//Precondicion: La PilaLsita no esta vacia
//Poscondicion: devuelve el dato en la posicion actual
template <class T>
const T& IteradorPilaLista<T>::ElementoActual() const {
	return this->pilaL->dato;
}


//Precondicion: La PilaLista no esta vacia
//Poscondicion: avanza en la PilaLista
template <class T>
void IteradorPilaLista<T>::Avanzar() {
		this->pilaL = this->pilaL->siguiente;
}

//Poscondicion: Reinicia el iterador a la posicion primera
template <class T>
void IteradorPilaLista<T>::Reiniciar() {
	this->pilaL = this->inicio;
}

//Falta implementar
//Poscondicion: clona el iterador
template <class T>
Puntero<Iteracion<T>> IteradorPilaLista<T>::Clonar() const{
	Iteracion<T>* t = new IteradorPilaLista(*this);
	return Puntero<Iteracion<T>>(t);
}


#endif