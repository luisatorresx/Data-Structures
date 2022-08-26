/*

Prueba de funcionamiento de las librerías ListaDoble y NodoDoble


*/
#include <iostream>
#include "ListaDoble.h"
using namespace std;


#define ASCENDENTE 1
#define DESCENDENTE 0

int main()
{
	ListaDoble<float> fLista;
	
	// Prueba con float
	fLista.insertar(20.01);
	fLista.insertar(15.12);
	fLista.insertar(42.03);
	fLista.insertar(31.04);
	
	fLista.mostrar(ASCENDENTE);
	fLista.mostrar(DESCENDENTE);
	
	fLista.primero();
	cout << "Primero: " << fLista.eActual() << endl;
	
	fLista.ultimo();
	cout << "Ultimo: " << fLista.eActual() << endl;
	
	cout << "Se eliminará un elemento" << endl;
	fLista.quitar(15.12);
	
	fLista.mostrar(ASCENDENTE);
	fLista.mostrar(DESCENDENTE);
	cin.get();
	return 0;
}


