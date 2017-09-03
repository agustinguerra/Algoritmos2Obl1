#pragma once

#include "Iterador.h"
#include "ColaPrioridadImp.h"

template <class T,class P>
class IteradorColaPrioridad : public Iteracion<T> {
public:
	//Pre: -
	//Poscondicion: el iterador de la cola prioridad
	~IteradorColaPrioridad() {}
	//Pre: -
	//Poscondicion: construye el iterador a la cola prioridad
	IteradorColaPrioridad(const Puntero<NodoListaPQ<T,P>>& iterable, int tope, int tamano);
	//Pre: -
	//Poscondicion: construye el iterador a la cola prioridad
	IteradorColaPrioridad(const Puntero<NodoListaPQ<T,P>>& iterable);
	//Pre: -
	//Poscondicion: devuelve true si el iterador de la cola prioridad tiene algun elemento. False en el caso contrario
	bool HayElemento() const override;
	//Precondicion: El iterador de la cola prioridad no esta vacia
	//Poscondicion: devuelve el dato en la posicion actual
	const T& ElementoActual() const override;
	//Precondicion: El iterador de la cola prioridad no esta vacia
	//Poscondicion: avanza en la cola prioridad
	void Avanzar() override;
	//Pre: -
	//Poscondicion: Reinicia el iterador a la posicion primera
	void Reiniciar() override;
	//Pre: -
	//Poscondicion: clona el iterador
	Puntero<Iteracion<T>> Clonar() const  override;

private:
	Puntero<NodoListaPQ<T,P>> inicio;
	Puntero<NodoListaPQ<T,P>> lista;
	int tope;
	int tamano;
};

#include "IteradorColaPrioridad.cpp"