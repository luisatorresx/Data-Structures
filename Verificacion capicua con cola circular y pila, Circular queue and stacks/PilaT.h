#include <iostream>
using namespace std;

template <class T>
class PilaT
{
	class NodoPila
	{
	public:
    	NodoPila* siguiente;
		T elemento;
		NodoPila(T x)
		{
			elemento = x;
			siguiente = NULL;
		}
	};

    NodoPila* cima;
public:
	PilaT()
	{
		cima = NULL;
	}
	void insertar(T elemento);
	T quitar();
	T cimaPila();
	bool pilaVacia();
	void limpiarPila();
	~PilaT()
	{
		limpiarPila();
	}
};

template <class T>
bool PilaT<T>::pilaVacia()
{
	return cima == NULL;
}

template <class T>
void PilaT<T>::insertar(T elemento)
{
		NodoPila* nuevo;
	nuevo = new NodoPila(elemento);
		nuevo -> siguiente = cima;
	cima = nuevo;
}

template <class T>
T PilaT<T>::quitar()
{
	if (pilaVacia())
		throw "Pila vacía, no se puede extraer.";

	T	aux = cima -> elemento;
	cima = cima -> siguiente;
	return aux;
}

template <class T>
T PilaT<T>:: cimaPila()
{
	if (pilaVacia())
		throw "Pila vacía";
	return cima -> elemento;
}

template <class T>
void PilaT<T>:: limpiarPila()
{
		NodoPila* n;
	while(!pilaVacia())
	{
		n = cima;
		cima = cima -> siguiente;
		delete n;
	}
}
