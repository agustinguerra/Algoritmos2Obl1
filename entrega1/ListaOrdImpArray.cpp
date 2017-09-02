#ifndef LISTAORDIMPARRAY_CPP
#define LISTAORDIMPARRAY_CPP

#include "ListaOrdImpArray.h"
//#include "IteradorListaOrdImpArray.h"


template <class T>
ListaOrdImpArray(const Comparador<T>& comp) {
	arrayDeLista = Array<T>(100);
	this->comparador = comp;
	this->posicion = -1;
	this->tamano = 100;
}

// PRE: Est� ordenada
// POS: e pertenece a la lista. La lista est� ordenada y contiene todos los elementos que hab�a en la lista antes de la inserci�n
template <class T>
void ListaOrdImp<T>::InsertarOrdenado(const T& e) {


}

// PRE: La lista no est� vac�a
// POS: Retorna el primer elemento de la lista
template <class T>
const T& ListaOrdImp<T>::Cabeza() const {
	return arrayDeLista[0];
}

// PRE: -
// POS: Elimina una ocurrencia del elemento de la lista si existe. De no existir no tiene acci�n.
template <class T>
void ListaOrdImp<T>::Eliminar(const T& e) {

}

// PRE: -
// POS: Retorna el largo de la lista
template <class T>
nat ListaOrdImp<T>::Largo() const {
	return this->posicion + 1;
}

// PRE: La lista tiene un elemento en la posici�n n. 
// POS: Retorna el elemento que est� en esa posici�n de la lista. El primer elemento empieza en 0.
template <class T>
const T& ListaOrdImp<T>::Obtener(const nat n) const {
	return arrayDeLista[n];
}

// PRE: -
// POS: Retorna true si y solo si el elemento e pertenece a la lista.
template <class T>
bool ListaOrdImp<T>::Pertenece(const T& e) const {
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
bool ListaOrdImp<T>::EstaVacia() const {
	if (this->posicion = -1) {
		return true;
	}
	else {
		return false;
	}
}

// PRE: -
// POS: Retorna un clon de la lista que no comparte memoria con ella
template <class T>
Puntero<ListaOrd<T>> ListaOrdImp<T>::Clon() const {
	return nullptr;
}

//PRE -
//POS: Devuelve el iterador de la lista
template <class T>
Iterador<T> ListaOrdImp<T>::ObtenerIterador() const {

}

#endif