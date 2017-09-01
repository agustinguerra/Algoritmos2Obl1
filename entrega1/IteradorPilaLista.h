#pragma once

#include "Pila.h"
#include "PilaLista.h"
#include "Iteracion.h"

template <class T>
class IteradorPilaLista : public Iteracion<T> {
public:
	//Poscondicion: destruye la PilaLista
	~IteradorPilaLista() {}
	//Poscondicion: construye el iterador a la PilaLista
	IteradorPilaLista(const ListaPila<T>& iterable,int tamano,int cantidadActual);
	//Poscondicion: construye el iterador a la PilaLista
	IteradorPilaLista(const Puntero<ListaPila<T>>& iterable);
	//Poscondicion: devuelve true si la PilaLista tiene algun elemento. False en el caso contrario
	bool HayElemento() const override;
	//Precondicion: La PilaLsita no esta vacia
	//Poscondicion: devuelve el dato en la posicion actual
	const T& ElementoActual() const override;
	//Precondicion: La PilaLista no esta vacia
	//Poscondicion: avanza en la PilaLista
	void Avanzar() override;
	//Poscondicion: Reinicia el iterador a la posicion primera
	void Reiniciar() override;
	//Poscondicion: clona el iterador
	Puntero<Iteracion<T>> Clonar() const  override;

private:
	Puntero<ListaPila<T>> inicio;
	Puntero<ListaPila<T>> pilaL;
	int tamano;
	int cantidadActual;
};

#include "IteradorPilaLista.cpp"