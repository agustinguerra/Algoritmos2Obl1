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
	
	actual = true;
	bool anterior = false;
	int largoDeOrigen = origen.Largo;
	Array<bool> validos(largoDeOrigen, true);

	for (int i = 0; i < largoDeOrigen; i++)
	{
		if (origen[i] == delimiter)
			validos[i] = false;
	}
	
	int contadorDeArrays = 0;
	for (int x = 0; x < (largoDeOrigen); x++)
	{
		actual = validos[x];

		if (anterior != actual && actual)
			contadorDeArrays++;

		anterior = actual;
	}

	Array<Cadena> retorno(contadorDeArrays, "");
	int indiceArraySplit = 0;
	int desde = 0, hasta = 0;
	for (nat i = 0; i < origen.Largo; i++)
	{
		if (validos[i])
			hasta = i;
		else
		{
			//Substring
			retorno[indiceArraySplit] = origen.SubCadena(desde, hasta - desde + 1);
			desde = i + 1;
			indiceArraySplit++;
		}
	}
	if (validos[origen.Largo - 1] && hasta == (origen.Largo - 1))
		retorno[indiceArraySplit] = origen.SubCadena(desde, hasta - desde + 1);

	return retorno;

	//nat largoCadena = origen.Largo;
	//int cantidadCadena = largoCadena;
	//int contador = 0;
	//int contadorAux = 0;
	//for (int i = 0; i < cantidadCadena; i++) {
	//	if (origen[i] != delimiter) {
	//		contadorAux = contadorAux + 1;
	//	}
	//	else {
	//		if (contadorAux > 0) {
	//			contador = contador + 1;
	//			contadorAux = 0;
	//		}
	//	}
	//}
	//if (contadorAux > 0) {
	//	contador = contador + 1;
	//}
	//Array<Cadena> retorno(contador);
	//for (int k = 0; k < contador; k++) {
	//	retorno[k] = "";
	//}
	//contadorAux = 0;
	//for (int j = 0; j < cantidadCadena; j++) {
	//	if (origen[j] != delimiter) {
	//		cout << origen[j];
	//		Cadena ins = Cadena(new char (origen[j])+'/0');
	//		retorno[contadorAux] = retorno[contadorAux] + ins;
	//	}
	//	else {
	//		contadorAux = contadorAux + 1;
	//	}
	//}
	//return retorno;
}
Cadena Sistema::Reverso(const Cadena& origen)
{
	return Cadena("");
}

#endif