#ifndef COLAPRIORIDADIMP_CPP
#define COLAPRIORIDADIMP_CPP

#include "ColaPrioridadImp.h"
//#include "IteradorColaPrioridad.h"


template <class T, class P>
ColaPrioridadImp<T, P>::ColaPrioridadImp() {
	this->tope = 0;
	this->tamano = 0;
}


template <class T, class P>
ColaPrioridadImp<T, P>::ColaPrioridadImp(int tam) {
	this->tope = tam;
	this->tamano = 0;
}

template <class T, class P>
ColaPrioridadImp<T, P>::ColaPrioridadImp(int tam, const Comparador<T>& compP, const Comparador<P>& compT) {
	this->tamano = tam;
	this->comparadorP = compP;
	this->comparadorT = compT;
}

// PRE: Está ordenada
// POS: e pertenece a la lista. La lista está ordenada y contiene todos los elementos que había en la lista antes de la inserción
template<class T,class P>
void ColaPrioridadImp<T,P>::insLista(const T& e, const P& p, Puntero<NodoListaPQ<T,P>>& l) {
	if (l == NULL) {
		Puntero<NodoListaPQ<T,P> > nodo = new NodoListaPQ<T,P>(e,p);
		nodo->siguiente = NULL;
		l = nodo;
	}
	else if (comparadorP.Comparar(l->prioridad, p) == MENOR) {
		Puntero<NodoListaPQ<T,P> > nodo = new NodoListaPQ<T,P>(l->dato,l->prioridad);
		nodo->siguiente = l->siguiente;
		l->siguiente = nodo;
		l->dato = e;
		l->prioridad = p;
	}
	else if ((comparadorP.Comparar(l->prioridad, p) == IGUALES)) {
		insLista(e,p, l->siguiente);
	}
	else if (comparadorP.Comparar(l->prioridad, p) == MAYOR) {
		insLista(e,p, l->siguiente);
	}
}


// PRE: -
// POS: Encola el elemento e con prioridad p
template <class T, class P>
void ColaPrioridadImp<T, P>::Encolar(const T& e, const P& p) {
	this->insLista(e, p, this->pq);
	this->tamano = this->tamano + 1;
}

// PRE: La cola no está vacía
// POS: Retorna el elemento de mayor prioridad en la cola eliminándolo
template <class T, class P>
const T& ColaPrioridadImp<T, P>::Desencolar() {
	ultimoDesencolado = this->pq->dato;
	tamano = tamano - 1;
	this->pq = this->pq->siguiente;
	return ultimoDesencolado;
}

// PRE: La cola no está vacía
// POS: Retorna el elemento de mayor prioridad en la cola sin eliminarlo
template <class T, class P>
const T& ColaPrioridadImp<T, P>::Cabeza() const {
	return this->pq->dato;
}

// PRE: -
// POS: Retorna el largo de la cola
template <class T, class P>
nat ColaPrioridadImp<T, P>::Largo() const {
	return this->tamano;
}

// PRE: El elemento e está en la cola
// POS: Retorna la instancia del elemento de mayor prioridad dentro de la cola.
template <class T, class P>
const T& ColaPrioridadImp<T, P>::ObtenerPrioridad(const T& e) const {
	Puntero<NodoListaPQ<T, P>> aux = this->pq;
	while (aux!=NULL) {
		if (comparadorT.Comparar(aux->dato, e) == IGUALES) {
			return aux->dato;
		}
	}
	return aux->dato;
}

// PRE: -
// POS: Retorna true si y solo si el elemento e pertenece a la cola.
template <class T, class P>
bool ColaPrioridadImp<T, P>::Pertenece(const T& e) const {
	Puntero<NodoListaPQ<T, P>> aux = this->pq;
	while (aux != NULL) {
		if (comparadorT.Comparar(aux->dato, e) == IGUALES) {
			return true;
		}
	}
	return false;
}

// PRE: -
// POS: Retorna true si y solo si la cola esta vacia
template <class T, class P>
bool ColaPrioridadImp<T, P>::EstaVacia() const {
	if (this->tamano == 0) {
		return true;
	}
	else {
		return false;
	}
}

// PRE: -
// POS: Retorna true si y solo si la cola esta llena7
template <class T, class P>
bool ColaPrioridadImp<T, P>::EstaLlena() const {
	if (this->tamano == this->tope) {
		return true;
	}
	else {
		return false;
	}
}

template <class T, class P>
Puntero<NodoListaPQ<T,P>> ColaPrioridadImp<T, P>::ClonarPQ(const Puntero<NodoListaPQ<T,P>>& original) const {
	if (original == nullptr) {
		return nullptr;
	}
	else {
		Puntero<NodoListaPQ<T,P>> nodoListaPQ;
		nodoListaPQ = new NodoListaPQ<T,P>(original->dato,original->prioridad);
		nodoListaPQ->siguiente = ClonarPQ(original->siguiente);
		return nodoListaPQ;
	}
}

// PRE: -
// POS: Retorna un clon de la cola que no comparte memoria con ella
template <class T, class P>
Puntero<ColaPrioridad<T, P>> ColaPrioridadImp<T, P>::Clon() const {
	Puntero<ColaPrioridadImp<T, P>> pqDevolver = new ColaPrioridadImp();
	pqDevolver->pq = ClonarPQ(this->pq);
	pqDevolver->tope = this->tope;
	pqDevolver->tamano = this->tamano;
	pqDevolver->ultimoDesencolado = this->ultimoDesencolado;
	pqDevolver->comparadorT = this->comparadorT;
	pqDevolver->comparadorP = this->comparadorP;
	return pqDevolver;
}

template <class T, class P>
Iterador<T> ColaPrioridadImp<T, P>::ObtenerIterador() const {
	//return new IteradorPQ<T>(this->pq);
	return nullptr;
}

#endif