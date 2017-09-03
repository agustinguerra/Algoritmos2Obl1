#ifndef ITERADORCOLAPRIORIDAD_CPP
#define ITERADORCOLAPRIORIDAD_CPP

#include "ColaPrioridadImp.h"
#include "IteradorColaPrioridad.h"
#include "Puntero.h"
#include <iostream>
#include <assert.h>
#include <typeinfo.h>
//Pre: -
//Poscondicion: construye el iterador a la cola prioridad
template <class T, class P>
IteradorColaPrioridad<T, P>::IteradorColaPrioridad(const Puntero<NodoListaPQ<T, P>>& iterable, int tope, int tamano) {
	this->inicio = iterable;
	this->lista = iterable;
	this->tamano = tamano;
	this->tope = tope;
}
//Pre: -
//Poscondicion: construye el iterador a la cola prioridad
template <class T, class P>
IteradorColaPrioridad<T, P>::IteradorColaPrioridad(const Puntero<NodoListaPQ<T, P>>& iterable) {
	this->inicio = iterable;
	this->lista = iterable;
}
//Pre: -
//Poscondicion: devuelve true si el iterador de la cola prioridad tiene algun elemento. False en el caso contrario
template <class T, class P>
bool IteradorColaPrioridad<T, P>::HayElemento() const {
	if (this->lista == NULL) {
		return false;
	}
	else {
		return true;
	}
}
//Precondicion: El iterador de la cola prioridad no esta vacia
//Poscondicion: devuelve el dato en la posicion actual
template <class T, class P>
const T& IteradorColaPrioridad<T, P>::ElementoActual() const {
	return this->lista->dato;
}
//Precondicion: El iterador de la cola prioridad no esta vacia
//Poscondicion: avanza en la cola prioridad
template <class T, class P>
void IteradorColaPrioridad<T, P>::Avanzar() {
	this->lista = this->lista->siguiente;
}
//Pre: -
//Poscondicion: Reinicia el iterador a la posicion primera
template <class T, class P>
void IteradorColaPrioridad<T, P>::Reiniciar() {
	this->lista = this->inicio;
}
//Pre: -
//Poscondicion: clona el iterador
template <class T, class P>
Puntero<Iteracion<T>> IteradorColaPrioridad<T, P>::Clonar() const {
	Iteracion<T>* t = new IteradorColaPrioridad(*this);
	return Puntero<Iteracion<T>>(t);
}

#endif