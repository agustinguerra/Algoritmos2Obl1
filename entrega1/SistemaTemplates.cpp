#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"
#include "PilaLista.h"
#include "PilaArray.h"
#include "Pila.h"
#include "IteradorPilaLista.h"


template <class T>
void merge(Array<T>& elementos, int l, int m, int r, const Comparador<T>& comp)
{
	int i, j, k;
	int numeroUno = m - l + 1;
	int numeroDos = r - m;

	Array<T> L(numeroUno);
	Array<T> R(numeroDos);

	for (i = 0; i < numeroUno; i++)
		L[i] = elementos[l + i];
	for (j = 0; j < numeroDos; j++)
		R[j] = elementos[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < numeroUno && j < numeroDos)
	{
		if(comp.Comparar(L[i],R[j]) == MENOR || comp.Comparar(L[i], R[j]) == IGUALES)
		{
			elementos[k] = L[i];
			i++;
		}
		else
		{
			elementos[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < numeroUno)
	{
		elementos[k] = L[i];
		i++;
		k++;
	}

	while (j < numeroDos)
	{
		elementos[k] = R[j];
		j++;
		k++;
	}
}



template <class T>
void mergeSortAux(Array<T>& elementos, int l, int r, const Comparador<T>& comp)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSortAux(elementos, l, m,comp);
		mergeSortAux(elementos, m + 1, r,comp);
		merge(elementos, l, m, r,comp);
	}
}



// Ejercicio 1: ordenamiento
//Se implemento un Merge Sort standard para ordenar y cumplir con los tiempos
//Poscondicion: ordena el arreglo
template <class T>
void Sistema::Ordenar(Array<T>& elementos, const Comparador<T>& comp)
{
	mergeSortAux(elementos,0, elementos.ObtenerLargo()-1, comp);
}

template <class T>
int busquedaBinaria(const Array<T>& elementos, int i, int d, const T& t, const Comparador<T>& comp)
{
	while (i <= d)
	{
		int medio = i + (d - i) / 2;
		if (comp.Comparar(elementos[medio],t) == IGUALES)
			return medio;
		if (comp.Comparar(elementos[medio], t) == MENOR)
			i = medio + 1;
		else
			d = medio - 1;
	}
	return -1;
}

// Operaci�n 2: B�squeda
//Se implemento una BS para cumplir con los tiempos
//Precondiciones: El array TIENE que estar ordenado. No lo chequeo porque es perjudicial para los tiempos
template <class T>
int Sistema::Busqueda(const Array<T>& elementos, const T& elem, const Comparador<T>& comp)
{
	int largo = elementos.ObtenerLargo();
	int retorno = busquedaBinaria(elementos, 0, largo - 1, elem, comp);
	return retorno;
}

// Operaci�n 3: TAD Pila
//Creador de Pila con lista simplemente encadenada
//Poscondicion: devuelve una pila con una lista simplemente encadenada
template <class T>
Puntero<Pila<T>> Sistema::CrearPilaSimplementeEncadenada(nat tamano)
{
	Puntero<Pila<T>> pila = new PilaLista<T>(tamano);
	return pila;
}

//Creador de Pila con array
//Poscondicion: devuelve una pila con un array
template <class T>
Puntero<Pila<T>> Sistema::CrearPilaArray(nat tamano)
{
	Puntero<Pila<T>> pila = new PilaArray<T>(tamano);
	return pila;
}


//Poscondiciones: Devuelvo TRUE si son iguales, o FALSE si no lo son
template <class T>
bool Sistema::Iguales(const Puntero<Pila<T>>& pila1, const Puntero<Pila<T>>& pila2, const Comparador<T>& comp)
{
	Iterador<T> itPila1 = pila1->ObtenerIterador();
	Iterador<T> itPila2 = pila2->ObtenerIterador();
	while (itPila1.HayElemento()) {
		T aux = itPila1.ElementoActual();
		itPila1.Avanzar();
		if (itPila2.HayElemento()) {
			T aux2 = itPila2.ElementoActual();
			if (comp.Comparar(aux2,aux) == IGUALES) {
				itPila2.Avanzar();
			}
		}
		else {
			return false;
		}
	}
	if ((!(itPila1.HayElemento())) && (!(itPila2.HayElemento()))) {
		return true;
	}
	else {
		return false;
	}
	return false;
}

// Operaci�n 5: Lista Ordenada
template<class T>
Puntero<ListaOrd<T>> Sistema::CrearListaOrdenadaEncadenada(const Comparador<T>& comp)
{
	return nullptr;
}

template <class T>
Puntero<ListaOrd<T>> Sistema::CrearListaOrdenadaConArray(const Comparador<T>& comp)
{
	return nullptr;
}
//Poscondiciones: Devuelve true si ambas listas son iguales. Sino false.
template <class T>
bool Sistema::ListasSonIguales(const Puntero<ListaOrd<T>>& lista1, const Puntero<ListaOrd<T>>& lista2, const Comparador<T>& comp)
{
	//bool retorno = false;
	//if (lista1->Largo() == lista2->Largo()) {
	//	retorno = true;
	//	nat largo = lista1->Largo();
	//	for (nat i = 0; i < largo; i++) {
	//		if (comp.Comparar(lista1->Obtener(i), lista2->Obtener(i) == IGUALES)) {}
	//		else {
	//			return false;
	//		}
	//	}
	//}
	//else {
	//	return false;
	//}
	//return retorno;
	return false;
}

// Operaci�n 6: Tad Cola de Prioridad
template<class T, class P>
Puntero<ColaPrioridad<T, P>> Sistema::CrearColaPrioridad(nat tamano)
{
	return nullptr;
}


// Operaci�n 7: Ejercicio con Cola de Prioridad
template <class T>
Array<T> Sistema::MayoresN(Array<Array<T>> datos, const Comparador<T>& comp, nat n)
{
	return Array<T>();
}

#endif