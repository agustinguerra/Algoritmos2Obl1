#pragma once

#include "ListaOrd.h"
#include "Iterador.h"
#include "ListaOrdImpArray.h"

template <class T>
class IteradorListaOrdArray : public Iteracion<T> {
public:
	//Poscondicion: destruye la IteradorListaOrdArray
	~IteradorListaOrdArray() {}
	//Poscondicion: construye el iterador a la ListaOrdArray
	IteradorListaOrdArray(const Array<T>& iterable, int tamano,int posicion);
	//Poscondicion: devuelve true si la ListaOrdArray tiene algun elemento. False en el caso contrario
	bool HayElemento() const override;
	//Precondicion: La ListaOrdArray no esta vacia
	//Poscondicion: devuelve el dato en la posicion actual
	const T& ElementoActual() const override;
	//Precondicion: La ListaOrdArray no esta vacia
	//Poscondicion: avanza en la ListaOrdArray
	void Avanzar() override;
	//Poscondicion: Reinicia el iterador a la posicion primera
	void Reiniciar() override;
	//Poscondicion: clona el iterador
	Puntero<Iteracion<T>> Clonar() const  override;


private:
	Array<T> arrayDeLista;
	int tamano;
	int posicion;
	int inicio;
};


#include "IteradorListaOrdArray.cpp"