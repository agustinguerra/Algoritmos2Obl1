#ifndef LISTAORDIMP_CPP
#define LISTAORDIMP_CPP

#include "ListaOrdImp.h"
//#include "IteradorPilaArray.h"

//PRE: -
//POS: Crea la lista ordenada
template <class T>
ListaOrdImp<T>::ListaOrdImp(const Comparador<T>& comp) {
	this->lista = nullptr;
	this->comparador = comp;
	this->largo = 0;
}


// PRE: Está ordenada
// POS: e pertenece a la lista. La lista está ordenada y contiene todos los elementos que había en la lista antes de la inserción
template<class T>
void ListaOrdImp<T>::insLista(const T& e, Puntero<NodoLista<T>>& l) {
	if (l->lista == NULL) {
		Puntero<NodoLista<T> > nodo = new NodoLista<T>(e);
		nodo->siguiente = NULL;
		l->lista = nodo;
	}
	else if (comparador.Comparar(l->lista->dato, e) == MAYOR) {
		Puntero<NodoLista<T> > nodo = new NodoLista<T>(l->lista->dato);
		nodo->siguiente = l->lista->siguiente;
		l->lista->siguiente = nodo;
		this->lista->dato = e;
	}
	else if ((comparador.Comparar(l->lista->dato, e) == IGUALES)) {
		InsLista(e, l->siguiente);
	}
	else if (comparador.Comparar(l->lista->dato, e) == MENOR) {
		InsLista(e, l->siguiente);
	}
}


// PRE: Está ordenada
// POS: e pertenece a la lista. La lista está ordenada y contiene todos los elementos que había en la lista antes de la inserción
template <class T>
void ListaOrdImp<T>::InsertarOrdenado(const T& e) {
	insLista(e, this->lista);
}

// PRE: La lista no está vacía
// POS: Retorna el primer elemento de la lista
template <class T>
const T& ListaOrdImp<T>::Cabeza() const {
	return this->lista->dato;
}

// PRE: -
// POS: Elimina una ocurrencia del elemento de la lista si existe. De no existir no tiene acción.
template <class T>
void ListaOrdImp<T>::Eliminar(const T& e) {
	//bool elimine = false;
	//Puntero<NodoLista<T>> aux = this->lista;
	//while (!elimine && this->lista != NULL) {
	//	if (comparador.Comparar(aux->dato, e) == IGUALES) {
	//		elimine = true;

	//	}
	//}
	//RECORDAR ACHICAR LARGO
}

// PRE: -
// POS: Retorna el largo de la lista
template <class T>
nat ListaOrdImp<T>::Largo() const {
	return this->largo;
}

// PRE: La lista tiene un elemento en la posición n. 
// POS: Retorna el elemento que está en esa posición de la lista. El primer elemento empieza en 0.
template <class T>
const T& ListaOrdImp<T>::Obtener(const nat n) const {
	Puntero<NodoLista<T>> aux = this->lista;
	for (int i = 0; i < n; i++) {
		aux = aux->siguiente;
	}
	return aux->dato;
}
// PRE: -
// POS: Retorna true si y solo si el elemento e pertenece a la lista.
template <class T>
bool ListaOrdImp<T>::Pertenece(const T& e) const {
	Puntero<NodoLista<T>> aux = this->lista;
	while (aux != NULL) {
		if (comparador.Comparar(aux->dato, e) == IGUALES) {
			break;
		}
	}
	if (aux == NULL) {
		return false;
	}
	else {
		return true;
	}
}

// PRE: -
// POS: Retorna true si y solo si la lista esta vacia
template <class T>
bool ListaOrdImp<T>::EstaVacia() const {
	if (this->lista == NULL) {
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
	Puntero<Lista<T> > ret = new ListaOrdImp<T>(this->comparador);
	Iterador<T> it = this->ObtenerIterador();
	while (it.HayElemento()){
		ret->InsertarOrdenado(it.ElementoActual());
		it.Avanzar();
	}
	return ret;
}

//PRE -
//POS: Devuelve el iterador de la lista
template <class T>
Iterador<T> ListaOrdImp<T>::ObtenerIterador() const {
	//return new IteradorListaImp<T>(*this);
	return nullptr;
}


#endif