#pragma once

#include "Pila.h"
#include "Array.h"
#include "Puntero.h"
#include "Puntero.cpp"
#include <iostream>


template <class T>
class PilaArray : public Pila<T> {
public:
	~PilaArray() {};
	PilaArray();

	//Constructor clon, tengo que ver si lo arreglo.
	//PilaLista(const PilaLista<T>&pila);
	PilaArray(int t);

	// Coloca el elemento e en el tope
	void Push(const T& e) override;

	Array<T> ClonarArray(const Array<T>& original) const;

	// Retorna el tope de la pila
	const T& Top() const override;

	// Borra el tope de la pila
	void Pop() override;

	// PREDICADOS

	// Retorna true si y solo si la lista esta llena
	bool EstaLlena() const override;

	// Retorna true si y solo si la lista esta vacia
	bool EstaVacia() const override;

	//Retorna un clon de la pila que no comparte memoria con ella
	Puntero<Pila<T>> Clon() const override;

	//Retorna el iterador para recorrer la pila
	Iterador<T> ObtenerIterador() const override;

private:
	Array<T> arrayDePila;
	int tamano;
	int posicion;
};

#include "PilaArray.cpp"