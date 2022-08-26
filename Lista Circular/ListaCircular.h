#include <iostream>
#include "Nodo.h"
using namespace std;

//CLASE LISTA CIRCULAR
class ListaCircular {
	private:
		Nodo* raiz;

	public:
		ListaCircular();
		~ListaCircular();
		void insertarPrimero(int x);
		void insertarUltimo(int x);
		bool vacia();
		void mostrar();
		int cantidad();
		void borrar(int pos);
		int infoActual() { return raiz->info;}
		void sumar(int v1, int v2);
		void verificarSuma();
};

//CONSTRUCTOR
ListaCircular::ListaCircular(){
	raiz = NULL;
}

//DESTRUCTOR
ListaCircular::~ListaCircular(){
	if (raiz != NULL) {
		Nodo* reco = raiz->sig;
		Nodo* bor;
		while (reco != raiz)
		{
			bor = reco;
			reco = reco->sig;
			delete bor;
		}
		delete raiz;
	}
}

//INSERTA UN ENTERO EN LA PRIMERA POSICION
void ListaCircular::insertarPrimero(int x){
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	if (raiz == NULL)
	{
		nuevo->sig = nuevo;
		nuevo->ant = nuevo;
		raiz = nuevo;
	}
	else
	{
		Nodo* ultimo = raiz->ant;
		nuevo->sig = raiz;
		nuevo->ant = ultimo;
		raiz->ant = nuevo;
		ultimo->sig = nuevo;
		raiz = nuevo;
	}
}

//INSERTA UN ENTERO EN LA ULTIMA POSICION
void ListaCircular::insertarUltimo(int x){
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	if (raiz == NULL)
	{
		nuevo->sig = nuevo;
		nuevo->ant = nuevo;
		raiz = nuevo;
	}
	else
	{
		Nodo* ultimo = raiz->ant;
		nuevo->sig = raiz;
		nuevo->ant = ultimo;
		raiz->ant = nuevo;
		ultimo->sig = nuevo;
	}
}

//VERIFICA SI ESTA VACIO
bool ListaCircular::vacia(){
	if (raiz == NULL)
		return true;
	else
		return false;
}

//IMPRIME LOS ELEMENTOS DE LA LISTA 
void ListaCircular::mostrar(){
	if (!vacia()) {
		Nodo* reco = raiz;
		do {
			cout << reco->info;
			reco = reco->sig;
		} while (reco != raiz);
		cout << "\n";
	}
}

//CANTIDAD DE ELEMENTOS EN LA LISTA
int ListaCircular::cantidad(){
	int cant = 0;
	if (!vacia())
	{
		Nodo* reco = raiz;
		do {
			cant++;
			reco = reco->sig;
		} while (reco != raiz);
	}
	return cant;
}

//BORRA UN ELEMENTO SEGUN SU POSICION
void ListaCircular::borrar(int pos){
	if (pos <= cantidad())
	{
		if (pos == 1)
		{
			if (cantidad() == 1)
			{
				delete raiz;
				raiz = NULL;
			}
			else
			{
				Nodo* bor = raiz;
				Nodo* ultimo = raiz->ant;
				raiz = raiz->sig;
				ultimo->sig = raiz;
				raiz->ant = ultimo;
				delete bor;
			}
		}
		else {
			Nodo* reco = raiz;
			for (int f = 1; f <= pos - 1; f++)
				reco = reco->sig;
			Nodo* bor = reco;
			Nodo* anterior = reco->ant;
			reco = reco->sig;
			anterior->sig = reco;
			reco->ant = anterior;
			delete bor;
		}
	}
}

//SUMA DOS ENTEROS
void ListaCircular::sumar(int d1, int d2){
	int resultado=d1+d2;
   Nodo* nuevo = new Nodo();
	nuevo->info = resultado;
	if (raiz == NULL)
	{
		nuevo->sig = nuevo;
		nuevo->ant = nuevo;
		raiz = nuevo;
	}
	else
	{
		Nodo* ultimo = raiz->ant;
		nuevo->sig = raiz;
		nuevo->ant = ultimo;
		raiz->ant = nuevo;
		ultimo->sig = nuevo;
	}
}

//VERIFICA QUE LA SUMA ESTE CORRECTA
void ListaCircular::verificarSuma(){
	if (!vacia()) {
		Nodo* reco = raiz;
		for(int i=0; i<(cantidad()-1); i++){
			if(reco->sig->info >= 10){
                reco->sig->info-=10;
                reco->info+=1;
			}
			reco = reco->sig;
  		}
	}
}
