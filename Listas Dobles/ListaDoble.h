
#include <iostream>
#include "NodoDoble.h"
using namespace std;


#define ASCENDENTE 1
#define DESCENDENTE 0

template<class T>
class ListaDoble {
public:
	ListaDoble() : plista(NULL) {}
	~ListaDoble();
	NodoDoble<T> *plista;	
	void insertar(T e){
		NodoDoble<T> *nuevo;
		
		primero();
		
		if(listaVacia()) {  //Se añade a la lista un nuevo nodo 
			nuevo = new NodoDoble<T>(e, plista);
			if(!plista) 
				plista = nuevo;
			else 
				plista->anterior = nuevo;
		}
		else { //Si ya hay elementos en la lista
			//Avanza hasta el último
			while(plista->siguiente) siguiente();
			nuevo = new NodoDoble<T>(e, plista->siguiente, plista);
			plista->siguiente = nuevo;
			if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
		}
		
	}
	void quitar(T e){
		NodoDoble<T> *pnodo;
		pnodo = plista;
		while(pnodo && pnodo->elemento < e) pnodo = pnodo->siguiente;
		while(pnodo && pnodo->elemento > e) pnodo = pnodo->anterior;
		
		if(!pnodo || pnodo->elemento != e) return;
		// Borrar el nodo
		
		if(pnodo->anterior) // no es el primer elemento
			pnodo->anterior->siguiente = pnodo->siguiente;
		if(pnodo->siguiente) // no el el ?ltimo nodo
			pnodo->siguiente->anterior = pnodo->anterior;
		}
	bool listaVacia() { 
		return plista == NULL; 
	}
	
	void mostrar(int orden){

	NodoDoble<T> *pnodo;
		if(orden == ASCENDENTE) {
			primero();
			pnodo = plista;
			while(pnodo) {
				cout << pnodo->elemento << "-> ";
				pnodo = pnodo->siguiente;
			}
		}
		else {
			ultimo();
			pnodo = plista;
			while(pnodo) {
				cout << pnodo->elemento << "-> ";
				pnodo = pnodo->anterior;
			}
		}
		cout << endl;
			
	}
	void siguiente(){
		if(plista) plista = plista->siguiente;
	}
	void anterior(){
		if(plista) plista = plista->anterior;
	}
	void primero(){
		while(plista && plista->anterior) 
			plista = plista->anterior;
	}
	void ultimo(){
		while(plista && plista->siguiente) 
			plista = plista->siguiente;
	}
	bool actual() {
		return plista != NULL;
	}
	T eActual() { 
	return plista->elemento; 
	}


};

template<class T>
ListaDoble<T>::~ListaDoble()
{
	NodoDoble<T> *aux;
	
	primero();
	while(plista) {
		aux = plista;
		plista = plista->siguiente;
		delete aux;
	}               
}
