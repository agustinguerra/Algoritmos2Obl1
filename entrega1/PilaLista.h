#pragma once



#include "Pila.h"
#include "Puntero.h"

#include <iostream>

template <class T>
class ListaPila {
public:
	T dato;
	Puntero<ListaPila<T>> siguiente;
	ListaPila(const T&dato) : dato(dato), siguiente(nullptr) {  };
};


template <class T>
class PilaLista : public Pila<T> {
public:
	~PilaLista() {};
	 PilaLista();
	 
	 PilaLista(int t);
	
	 // Coloca el elemento e en el tope
	 void Push(const T& e) override;

	 
	 Puntero<ListaPila<T>> ClonarLista(const Puntero<ListaPila<T>>& original) const;

	 PilaLista(const PilaLista<T>&pila);
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
	Puntero<ListaPila<T>> lista;
	int tamano;
	int cantidadActual;
};

#include "PilaLista.cpp"