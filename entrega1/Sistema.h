#ifndef SISTEMA_H
#define SISTEMA_H

#include "Cadena.h"
#include "Iterador.h"
#include "Puntero.h"
#include "Tupla.h"
#include "Pila.h"
#include "ListaOrd.h"
#include "ColaPrioridad.h"

class Sistema
{
public:
	Sistema();
	~Sistema();

	// Ejercicio 1: ordenamiento
	template <class T>
	void Ordenar(Array<T>& elementos, const Comparador<T>& comp);
	void OrdenarEnteros(Array<int>& elementos);

	// Operación 2: Búsqueda
	template <class T>
	int Busqueda(const Array<T>& elementos, const T& elem, const Comparador<T>& comp);
	bool ExisteSuma(const Array<int>& elementos, int suma);

	// Operación 3: TAD Pila
	template <class T>
	Puntero<Pila<T>> CrearPilaSimplementeEncadenada(nat tamano);

	template <class T>
	Puntero<Pila<T>> CrearPilaArray(nat tamano);

	template <class T>
	bool Iguales(const Puntero<Pila<T>>& pila1, const Puntero<Pila<T>>& pila2, const Comparador<T>& comp);

	// Operacion 4: Cadenas
	Array<Cadena> Split(const Cadena& origen, char delimiter);
	Cadena Reverso(const Cadena& origen);

	// Operación 5: Lista Ordenada
	template <class T>
	Puntero<ListaOrd<T>> CrearListaOrdenadaEncadenada(const Comparador<T>& comp = Comparador<T>::Default);

	template <class T>
	Puntero<ListaOrd<T>> CrearListaOrdenadaConArray(const Comparador<T>& comp = Comparador<T>::Default);

	template <class T>
	bool ListasSonIguales(const Puntero<ListaOrd<T>>& lista1, const Puntero<ListaOrd<T>>& lista2, const Comparador<T>& comp);

	// Operación 6: Tad Cola Prioridad
	template <class T, class P>
	Puntero<ColaPrioridad<T, P>> CrearColaPrioridad(nat tamano);

	// Operación 7: Ejercicio con Cola Prioridad
	template <class T>
	Array<T> MayoresN(Array<Array<T>> datos, const Comparador<T>& comp, nat n);


private:
};

#include "SistemaTemplates.cpp"

#endif
