#pragma once

#include "ListaOrd.h"
#include "Puntero.h"
#include <iostream>

template <class T>
class NodoLista {
public:
	T dato;
	Puntero<NodoLista<T>> siguiente;
	NodoLista(const T&dato) : dato(dato), siguiente(nullptr) {  };
};

template <class T>
class ListaOrdImp : public ListaOrd<T> {
public:
	~ListaOrdImp() {};
	//PRE: -
	//POS: Construye la lista ordenada
	ListaOrdImp(const Comparador<T>& comp);

	// PRE: Est� ordenada
	// POS: e pertenece a la lista. La lista est� ordenada y contiene todos los elementos que hab�a en la lista antes de la inserci�n
	void ListaOrdImp<T>::insLista(const T& e, Puntero<NodoLista<T>>& l);

	// PRE: Est� ordenada
	// POS: e pertenece a la lista. La lista est� ordenada y contiene todos los elementos que hab�a en la lista antes de la inserci�n
	void InsertarOrdenado(const T& e) override;

	// PRE: La lista no est� vac�a
	// POS: Retorna el primer elemento de la lista
	const T& Cabeza() const override;

	// PRE: -
	// POS: Elimina una ocurrencia del elemento de la lista si existe. De no existir no tiene acci�n.
	void Eliminar(const T& e) override;

	// PRE: -
	// POS: Retorna el largo de la lista
	nat Largo() const override;

	// PRE: La lista tiene un elemento en la posici�n n. 
	// POS: Retorna el elemento que est� en esa posici�n de la lista. El primer elemento empieza en 0.
	const T& Obtener(const nat n) const override;

	// PRE: -
	// POS: Retorna true si y solo si el elemento e pertenece a la lista.
	bool Pertenece(const T& e) const override;

	// PRE: -
	// POS: Retorna true si y solo si la lista esta vacia
	bool EstaVacia() const override;

	// PRE: -
	// POS: Retorna un clon de la lista que no comparte memoria con ella
	Puntero<ListaOrd<T>> Clon() const override;

	//PRE -
	//POS: Devuelve el iterador de la lista
	Iterador<T> ObtenerIterador() const override;

private:
	Puntero<NodoLista<T>> lista;
	Comparador<T> comparador;
	int largo;
};

#include "ListaOrdImp.cpp"