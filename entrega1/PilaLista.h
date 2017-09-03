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
	//Pre: -
	//Pos: destruye la pila lista
	~PilaLista() {};
	//Pre: -
	//Pos: construye la pila lista
	 PilaLista();
	 //Pre: -
	 //Pos: construye la pila lista
	 PilaLista(int t);
	
	 // Coloca el elemento e en el tope
	 //Precondicion: la pila no es llena
	 //Poscondicion: Queda el elemento en el tope de la pila.
	 void Push(const T& e) override;

	 //PRE: -
	 //Poscondicion: devuelve un clon de la lista que no comparte memoria
	 Puntero<ListaPila<T>> ClonarLista(const Puntero<ListaPila<T>>& original) const;

	 //Constructor clon. Construye una PilaLista clonando la que se le pasa por parametro
	 //Precondicion: PilaLista no vacia
	 //Poscondicion: Construye una PilaLista clon

	 PilaLista(const PilaLista<T>&pila);
	// Retorna el tope de la pila
	//Precondicion: la pila no es vacia
	//Poscondicion: devuelve el primer elemento de la pila

	 const T& Top() const override;

	// Borra el tope de la pila
	//Precondicion: la pila no es vacia
	//Poscondicion: elimina el primer elemento de la pila
	 void Pop() override;

	// PREDICADOS

	// Retorna true si y solo si la lista esta llena
	//Precondicion: la pila no es vacia
	//Poscondicion: retorna true si la pila esta llena, sino false
	 bool EstaLlena() const override;

	// Retorna true si y solo si la lista esta vacia
	//Pre: -
	//Precondicion: devuelve true si la pila esta vacia, false si no lo esta.
	 bool EstaVacia() const override;

	//Retorna un clon de la pila que no comparte memoria con ella
	//Pre: -
	//Pos: devuelve un clon que no comparte memoria
	 Puntero<Pila<T>> Clon() const override;

	 //Retorna el iterador para recorrer la pila
	 //PRE: -
	 //Poscondicion: retorna el iterador para recorrer la pila
	 Iterador<T> ObtenerIterador() const override;

private:
	Puntero<ListaPila<T>> lista;
	int tamano;
	int cantidadActual;
};

#include "PilaLista.cpp"