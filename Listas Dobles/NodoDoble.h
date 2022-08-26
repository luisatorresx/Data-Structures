#include <iostream>
using namespace std;

template<class T>
class NodoDoble {
public:
	NodoDoble(T v, NodoDoble<T> *sig = NULL, NodoDoble<T> *ant = NULL) :
		elemento(v), siguiente(sig), anterior(ant) {}
	T elemento;
	NodoDoble<T> *siguiente;
	NodoDoble<T> *anterior;
};
