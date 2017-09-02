#ifndef SISTEMA_CPP
#define SISTEMA_CPP

#include "Sistema.h"

Sistema::Sistema()
{
}
Sistema::~Sistema()
{
}

// Ejercicio 1: ordenamiento
//Al saber la cantidad de elementos, puedo transformarlo en orden n. El siguiente algoritmo recorre el array original, y lo va guardando en uno nuevo de tamaño fijo que permite re armar el original recorriendolo de manera lineal luego.
//Precondiciones: numeros pares naturales menores a 6000. 
void Sistema::OrdenarEnteros(Array<int>& elementos)
{
	Array<int> total(6002);
	for (int t = 0; t < 6002; t++) {
		total[t] = 0;
	}
	int largo = elementos.ObtenerLargo();
	for (int i = 0; i < largo; i++) {
		total[elementos[i] + 1] = total[elementos[i] + 1] + 1;
	}
	int cantidadElementos = largo;
	int iteradorEnGrande = 0;
	int iterador = 0;
	while (iterador < cantidadElementos) {
		if (total[iteradorEnGrande + 1] != 0) {
			for (int k = 0; k < total[iteradorEnGrande + 1]; k++) {			
				elementos[iterador] = iteradorEnGrande;
				iterador++;
			}
		}
		iteradorEnGrande++;
	}
}

// Operación 2: Búsqueda
//Primero lo ordeno con el algoritmo ya implementado, tiempo n log n. Luego, para cada elemento con busqueda binaria busco la suma. Si la encuentro devuelvo true, sino no.
//Poscondiciones: devuelve false si no lo encuentra, o true si lo encuentra
bool Sistema::ExisteSuma(const Array<int>& elementos, int suma)
{
	Array<int> copia(elementos.ObtenerLargo());
	int largo = elementos.ObtenerLargo();
	for (int i = 0; i < largo; i++) {
		copia[i] = elementos[i];
	}
	int esta = -1;
	Ordenar<int>(copia, Comparador<int>::Default);
	for (int t = 0; t < largo; t++) {
		Array<int> copiaSinEle(largo - 1);
		Array<int>::Copiar(copia, 0, t, copiaSinEle, 0);
		Array<int>::Copiar(copia, t + 1, copiaSinEle, t);
		esta = Busqueda<int>(copiaSinEle, suma - copia[t], Comparador<int>::Default);
		if (esta != -1) {
			return true;
		}
	}
	return false;
}

// Operacion 4: Cadenas
Array<Cadena> Sistema::Split(const Cadena& origen, char delimiter)
{
	return Array<Cadena>();
}
Cadena Sistema::Reverso(const Cadena& origen)
{
	return Cadena("");
}

#endif