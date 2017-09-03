#pragma once


#include "Iterable.h"
#include "Puntero.h"
#include "ColaPrioridad.h"

typedef unsigned int nat;

template <class T, class P>
class NodoListaPQ {
public:
	T dato;
	P prioridad;
	Puntero<NodoListaPQ<T,P>> siguiente;
	NodoListaPQ(const T&dato,const P&prioridad) : dato(dato), prioridad(prioridad), siguiente(nullptr) {  };
};

template <class T, class P>
class ColaPrioridadImp : public ColaPrioridad<T,P>
{
public:
	//PRE: -
	//POS: Destruye la cola prioridad
	~ColaPrioridadImp() {}
	//PRE: -
	//POS: Construye la cola prioridad
	ColaPrioridadImp();
	//PRE: -
	//POS: Construye la cola prioridad
	ColaPrioridadImp(int tamano);
	//PRE: -
	//POS: Construye la cola prioridad
	ColaPrioridadImp(int tam, const Comparador<T>& compP, const Comparador<P>& compT);

	// PRE: -
	// POS: Inserta el elemento en la lista de la PQ de manera ordenada
	void ColaPrioridadImp<T, P>::insLista(const T& e, const P& p, Puntero<NodoListaPQ<T, P>>& l);

	// PRE: -
	// POS: Encola el elemento e con prioridad p
	void Encolar(const T& e, const P& p) override;

	// PRE: La cola no está vacía
	// POS: Retorna el elemento de mayor prioridad en la cola eliminándolo
	const T& Desencolar() override;

	// PRE: La cola no está vacía
	// POS: Retorna el elemento de mayor prioridad en la cola sin eliminarlo
	const T& Cabeza() const override;

	// PRE: -
	// POS: Retorna el largo de la cola
	nat Largo() const override;

	// PRE: El elemento e está en la cola
	// POS: Retorna la instancia del elemento de mayor prioridad dentro de la cola.
	const T& ObtenerPrioridad(const T& e) const override;

	// PRE: -
	// POS: Retorna true si y solo si el elemento e pertenece a la cola.
	bool Pertenece(const T& e) const override;

	// PRE: -
	// POS: Retorna true si y solo si la cola esta vacia
	bool EstaVacia() const override;

	// PRE: -
	// POS: Retorna true si y solo si la cola esta llena
	bool EstaLlena() const override;

	Puntero<NodoListaPQ<T, P>> ClonarPQ(const Puntero<NodoListaPQ<T, P>>& original) const;

	// PRE: -
	// POS: Retorna un clon de la cola que no comparte memoria con ella
	Puntero<ColaPrioridad<T, P>> Clon() const override;

	//Retorna el iterador para recorrer la PQ
	Iterador<T> ObtenerIterador() const override;

private:
	Puntero<NodoListaPQ<T,P>> pq;
	Comparador<P> comparadorP;
	Comparador<T> comparadorT;
	int tope;
	int tamano;
	T ultimoDesencolado;
};



#include "ColaPrioridadImp.cpp"