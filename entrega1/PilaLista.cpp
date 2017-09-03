

#ifndef PILALISTA_CPP
#define PILALISTA_CPP

#include "PilaLista.h"
#include "Puntero.h"
#include <iostream>
#include <assert.h>
#include <typeinfo.h>
#include "IteradorPilaLista.h"

//Pre: -
//Pos: construye la pila lista
template <class T>
PilaLista<T>::PilaLista() {
	this->lista = NULL;
	tamano = 0;
	cantidadActual = 0;
}

//Pre: -
//Pos: construye la pila lista
template <class T>
PilaLista<T>::PilaLista(int t) {
	this->lista = NULL;
	tamano = t;
	cantidadActual = 0;
}


// Coloca el elemento e en el tope
//Precondicion: la pila no es llena
//Poscondicion: Queda el elemento en el tope de la pila.
template <class T>
void PilaLista<T>::Push(const T& e) {
	if (!(this->EstaLlena())) {
		Puntero<ListaPila<T>> aux = new ListaPila<T>(e);
		aux->siguiente = this->lista;
		this->lista = aux;
		this->cantidadActual = this->cantidadActual + 1;
	}
}

// Retorna el tope de la pila
//Precondicion: la pila no es vacia
//Poscondicion: devuelve el primer elemento de la pila
template <class T>
const T& PilaLista<T>::Top() const {
	return this->lista->dato;

}

// Borra el tope de la pila
//Precondicion: la pila no es vacia
//Poscondicion: elimina el primer elemento de la pila
template <class T>
void PilaLista<T>::Pop() {
	this->lista = this->lista->siguiente;
	this->cantidadActual = this->cantidadActual - 1;
}

// PREDICADOS

// Retorna true si y solo si la lista esta llena
//Precondicion: la pila no es vacia
//Poscondicion: retorna true si la pila esta llena, sino false
template <class T>
bool PilaLista<T>::EstaLlena() const {
	if (!(this->EstaVacia())) {
		if (this->cantidadActual == this->tamano) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

// Retorna true si y solo si la lista esta vacia
//Pre: -
//Precondicion: devuelve true si la pila esta vacia, false si no lo esta.
template <class T>
bool PilaLista<T>::EstaVacia() const {
	if (this->lista == nullptr) {
		return true;
	}
	else {
		return false;
	}
}




//Constructor clon. Construye una PilaLista clonando la que se le pasa por parametro
//Precondicion: PilaLista no vacia
//Poscondicion: Construye una PilaLista clon
template <class T>
PilaLista<T>::PilaLista(const PilaLista<T>&pila) {
	lista = ClonarLista(pila.lista);
	tamano = pila.tamano;
	cantidadActual = pila.cantidadActual;
}

//Retorna un clon de la pila que no comparte memoria con ella
//Pre: -
//Pos: devuelve un clon que no comparte memoria
template <class T>
Puntero<Pila<T>> PilaLista<T>::Clon() const {
	Puntero<PilaLista<T>> pilaDevolver = new PilaLista(*this);
	return pilaDevolver;
}


//Clonador de la lista de la pila
//PRE: -
//Poscondicion: devuelve un clon de la lista que no comparte memoria
template <class T>
Puntero<ListaPila<T>> PilaLista<T>::ClonarLista(const Puntero<ListaPila<T>>& original) const {
	if (original == nullptr) {
		return nullptr;
	}
	else {
		Puntero<ListaPila<T>> nodoLista;
		nodoLista = new ListaPila<T>(original->dato);
		nodoLista->siguiente = ClonarLista(original->siguiente);
		return nodoLista;
	}
}

//Retorna el iterador para recorrer la pila
//PRE: -
//Poscondicion: retorna el iterador para recorrer la pila
template <class T>
Iterador<T> PilaLista<T>::ObtenerIterador() const{
	return new IteradorPilaLista<T>(this->lista);
}

#endif