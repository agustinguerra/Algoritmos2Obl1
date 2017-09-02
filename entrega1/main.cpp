#include "CasoDePrueba.h"
#include "PruebaMemoria.h"
#include "ConductorPrueba.h"
#include "Sistema.h"

Puntero<Sistema> Inicializar()
{
	return new Sistema();
}



void imprimirLista(Iterador<int>& iter) {
	while (iter.HayElemento()) {
		cout << iter.ElementoActual() << ", ";
		iter.Avanzar();
	}
	cout << endl << endl;
	iter.Reiniciar();
}

void test_lista_encadenada()
{
	Comparador<int> comp = Comparador<int>();

	Puntero<ListaOrd<int>> miLista = new ListaOrdImp<int>(comp);
	cout << "Agrego los numeros 5, 4, 6, 3, 2, 1 a la lista" << endl;
	miLista->InsertarOrdenado(5);
	miLista->InsertarOrdenado(4);
	miLista->InsertarOrdenado(6);
	miLista->InsertarOrdenado(3);
	miLista->InsertarOrdenado(2);
	miLista->InsertarOrdenado(1);

	Puntero<ListaOrd<int>> miClon = miLista->Clon();

	Iterador<int> iter = miLista->ObtenerIterador();
	imprimirLista(iter);

	cout << "Este es el clon: ";
	imprimirLista(miClon->ObtenerIterador());

	cout << "Elimino el primero (1)" << endl;
	miLista->Eliminar(1);
	imprimirLista(miLista->ObtenerIterador());

	cout << "Elimino el ultimo (6)" << endl;
	miLista->Eliminar(6);
	imprimirLista(miLista->ObtenerIterador());

	cout << "Elimino caso generico (3) y (4)" << endl;
	miLista->Eliminar(3);
	miLista->Eliminar(4);
	imprimirLista(miLista->ObtenerIterador());

	cout << "Obtener(0) = 1 ? " << miClon->Obtener(0) << endl;
	cout << "Obtener(5) = 6 ? " << miClon->Obtener(5) << endl;
	cout << "Obtener(2) = 3 ? " << miClon->Obtener(2) << endl;

	miLista->Eliminar(2);
	miLista->Eliminar(5);
	cout << "Elimino 2 y 5 de miLista, queda vacia?" << miLista->EstaVacia() << endl;

	std::cout << "Nueva lista, 3, es elemento repetido (2,3,3,4,5)" << endl;
	Puntero<ListaOrd<int>> listaRepetida = new ListaOrdImp<int>(comp);
	listaRepetida->InsertarOrdenado(5);
	listaRepetida->InsertarOrdenado(4);
	listaRepetida->InsertarOrdenado(3);
	listaRepetida->InsertarOrdenado(2);
	listaRepetida->InsertarOrdenado(3);

	Iterador<int> itRepetido = listaRepetida->ObtenerIterador();
	imprimirLista(itRepetido);

	std::cout << endl << endl << "Elimino el 3 y el 1, el 1 no esta. res = (2,3,4,5) = ";
	listaRepetida->Eliminar(3);
	listaRepetida->Eliminar(1);
	auto it2 = listaRepetida->ObtenerIterador();
	imprimirLista(it2);
}

void test_pila_array()
{
	Puntero<Pila<int>> pila = new PilaArray<int>(6);
	std::cout << "Esta vacia la pila ? (Si) " << pila->EstaVacia() << endl;

	std::cout << "Pusheando 1,2,3,4,5 ..." << endl;

	pila->Push(1);
	pila->Push(2);
	pila->Push(3);
	pila->Push(4);
	pila->Push(5);

	std::cout << "A esta altura la pila deberia estar llena, esta? " << pila->EstaLlena() << endl;
	std::cout << "Push 6" << endl;
	pila->Push(6);

	cout << "El top deberia ser 6. Y es:" << pila->Top() << endl;

	cout << "Clonando la pila." << endl;
	pila->Clon();


}

void test_pila_lista()
{
	Puntero<Pila<int>> pila = new PilaLista<int>(5);

	std::cout << "Esta vacia la pila ? (Si) " << pila->EstaVacia() << endl;

	std::cout << "Pusheando 1,2,3,4,5 ..." << endl;

	pila->Push(1);
	pila->Push(2);
	pila->Push(3);
	pila->Push(4);
	pila->Push(5);

	std::cout << "A esta altura la pila deberia estar llena, esta? " << pila->EstaLlena() << endl;
	std::cout << "Push 6" << endl;
	pila->Push(6);

	cout << "El top deberia ser 6. Y es:" << pila->Top() << endl;

	cout << "Clonando la pila." << endl;
	pila->Clon();


}

void test_pila_iterador_lista()
{
	Puntero<Pila<int>> pila = new PilaLista<int>(5);
	std::cout << "Pusheando 1,2,3,4,5 ..." << endl;

	pila->Push(1);
	pila->Push(2);
	pila->Push(3);
	pila->Push(4);
	pila->Push(5);

	Iterador<int> iter = pila->ObtenerIterador();

	std::cout << "Popping el stack..." << endl;;
	imprimirLista(iter);

	std::cout << "Top = 5? " << pila->Top() << endl;

	pila->Pop();
	std::cout << "Pop 5, Top = 4?" << pila->Top() << endl;

	pila->Pop(); //4
	pila->Pop(); //3
	pila->Pop(); //2
	pila->Pop(); //1

	std::cout << "Popped todo, esta vacia la pila? si" << pila->EstaVacia() << endl;;
}

void test_pila_iterador_array()
{
	Puntero<Pila<int>> pila = new PilaArray<int>(5);
	std::cout << "Pusheando 1,2,3,4,5 ..." << endl;

	pila->Push(1);
	pila->Push(2);
	pila->Push(3);
	pila->Push(4);
	pila->Push(5);

	std::cout << "Esta llena la pila? (si) " << pila->EstaLlena() << endl;;
	Iterador<int> iter = pila->ObtenerIterador();

	std::cout << "Popping el stack..." << endl;
	imprimirLista(iter);

	std::cout << "Top = 5? " << pila->Top() << endl;

	pila->Pop();
	std::cout << "Pop 5, Top = 4?" << pila->Top() << endl;

	pila->Pop(); //4
	pila->Pop(); //3
	pila->Pop(); //2
	pila->Pop(); //1

	std::cout << "Popped todo, esta vacia la pila? si" << pila->EstaVacia() << endl;;
}

void main()
{
	Puntero<ConductorPrueba> cp = new ConductorPrueba();
	Array<Puntero<Prueba>> pruebas = Array<Puntero<Prueba>>(3);
	pruebas[0] = new PruebaMemoria();
	pruebas[1] = new CasoDePrueba(Inicializar);
	pruebas[2] = pruebas[0];
	cp->CorrerPruebas(pruebas.ObtenerIterador());

	 //test_lista_encadenada();
	 //test_pila_array();
	 //test_pila_lista();
	// test_pila_iterador_lista();
	// test_pila_iterador_array();
	// test_pqueue_lista();
	system("pause");
}
