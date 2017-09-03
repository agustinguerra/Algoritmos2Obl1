#ifndef LISTAORDIMPARRAY_CPP
#define LISTAORDIMPARRAY_CPP

#include "ListaOrdImpArray.h"
#include "IteradorListaOrdArray.h"


template <class T>
ListaOrdImpArray<T>::ListaOrdImpArray(const Comparador<T>& comp) {
	arrayDeLista = Array<T>(100);
	this->comparador = comp;
	this->posicion = -1;
	this->tamano = 100;
}

template <class T>
ListaOrdImpArray<T>::ListaOrdImpArray() {
}
// PRE: Está ordenada
// POS: e pertenece a la lista. La lista está ordenada y contiene todos los elementos que había en la lista antes de la inserción
template <class T>
void ListaOrdImpArray<T>::InsertarOrdenado(const T& e) {
	if (this->posicion == this->tamano - 1) {
		Array<T> nueva(this->tamano * 2);
		Array<T>::Copiar(this->arrayDeLista, nueva, 0);
		this->arrayDeLista = nueva;
		this->tamano = this->tamano * 2;
	}
	if (this->posicion == -1) {
		this->posicion = this->posicion + 1;
		this->arrayDeLista[0] = e;
	}
	else {
		this->posicion = this->posicion + 1;
		int posicionActual = this->posicion;
		if (posicionActual > 0) {
			while (posicionActual > 0 && this->comparador.Comparar(e, this->arrayDeLista[posicionActual]) == MAYOR) {
				this->arrayDeLista[posicionActual] = this->arrayDeLista[posicionActual - 1];
				posicionActual--;
			}
			this->arrayDeLista[posicionActual] = e;
		}
		else {
			this->arrayDeLista[posicionActual] = e;
		}
	}
}

// PRE: La lista no está vacía
// POS: Retorna el primer elemento de la lista
template <class T>
const T& ListaOrdImpArray<T>::Cabeza() const {
	return arrayDeLista[0];
}

// PRE: -
// POS: Elimina una ocurrencia del elemento de la lista si existe. De no existir no tiene acción.
template <class T>
void ListaOrdImpArray<T>::Eliminar(const T& e) {
	int pos = 0;
	bool encontre = false;
	int donde = -1;
	while (pos <= this->posicion && !encontre) {
		if (this->comparador.Comparar(this->arrayDeLista[pos], e) == IGUALES) {
			encontre = true;
			donde = pos;
		}
		pos = pos + 1;
	}
	if (encontre) {
		for (int i = donde; i <= this->posicion; i++) {
			this->arrayDeLista[i] = this->arrayDeLista[i + 1];
		}
		this->posicion = this->posicion - 1;
	}
}

// PRE: -
// POS: Retorna el largo de la lista
template <class T>
nat ListaOrdImpArray<T>::Largo() const {
	return this->posicion + 1;
}

// PRE: La lista tiene un elemento en la posición n. 
// POS: Retorna el elemento que está en esa posición de la lista. El primer elemento empieza en 0.
template <class T>
const T& ListaOrdImpArray<T>::Obtener(const nat n) const {
	return arrayDeLista[n];
}

// PRE: -
// POS: Retorna true si y solo si el elemento e pertenece a la lista.
template <class T>
bool ListaOrdImpArray<T>::Pertenece(const T& e) const {
	int largo = this->posicion;
	for (int i = 0; i < largo + 1; i++) {
		if (comparador.Comparar(arrayDeLista[i], e) == IGUALES) {
			return true;
		}
	}
	return false;
}

// PRE: -
// POS: Retorna true si y solo si la lista esta vacia
template <class T>
bool ListaOrdImpArray<T>::EstaVacia() const {
	if (this->posicion == -1) {
		return true;
	}
	else {
		return false;
	}
}

// PRE: -
// POS: Retorna un clon de la lista que no comparte memoria con ella
template <class T>
Puntero<ListaOrd<T>> ListaOrdImpArray<T>::Clon() const {
	Array<T> devolver(tamano);
	Array<T>::Copiar(arrayDeLista, devolver, 0);
	Puntero<ListaOrdImpArray<T>> listaDevolver = new ListaOrdImpArray();
	listaDevolver->arrayDeLista = devolver;
	listaDevolver->tamano = tamano;
	listaDevolver->posicion = posicion;
	listaDevolver->comparador = comparador;
	return listaDevolver;
}

//PRE -
//POS: Devuelve el iterador de la lista
template <class T>
Iterador<T> ListaOrdImpArray<T>::ObtenerIterador() const {
	return new IteradorListaOrdArray<T>(this->arrayDeLista,this->tamano,this->posicion);
}

#endif