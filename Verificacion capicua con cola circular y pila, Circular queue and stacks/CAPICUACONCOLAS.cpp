/*Asignación 5.
Uso de cola con arreglo circular para determinar si un número es capicúa

En este ejercicio se encuentran incluidas las funciones de colas
*/

#include <iostream>
#include <string>
#include "PilaT.h"
using namespace std;
const int maxE=10;


template<class T>
class Cola{
	T C[maxE];
	int primero,ultimo;
	
public:
	Cola(){
		//Se crea la cola vacía
		primero=0;
		ultimo=0;
	}
	void insertar(T elem){
		C[ultimo]=elem;
		if(ultimo==(maxE-1))
			ultimo=0;
		else 
			ultimo++;
	}
	T retirar(){
		T x = C[primero];
		if(primero==(maxE-1))
			primero =0;
		else
			primero++;
		return x;
	}
			
	bool colaVacia(){
		if(primero==ultimo)
			return true;
		return false;
	}
};


int main() {
	PilaT<char> pila;
	Cola<char> cola;
	string elem;
	char resp;
	
	do{
		bool capicua = true;
		cout<<"Ingrese el número a evaluar, este debe tener máximo 10 dígitos :)"<<endl;
		cin>>elem;
		
		//Se llenan la pila y la cola con el número
		for(char c : elem){
			pila.insertar(c);
			cola.insertar(c);
		}
		//Se van sacando y comparando uno a uno los elementos que estan en la cola y en la pila, de esta manera se compara el primer numero con el ultimo
		while(!cola.colaVacia()&&!pila.pilaVacia()){
			if(pila.quitar()!=cola.retirar()){
				capicua=false;
			}
		}
		
		if(capicua){
			cout<<elem<<" es capicúa :)"<<endl;
		}else
		   cout<<elem<<" no es capicúa."<<endl;	
		cout<<endl<<endl<<"Presiona S si deseas evaluar otra expresión :)"<<endl;
		cin>>resp;
	} while(resp=='S'||resp=='s');
	cout<<"Fue un placer ayudarte :)";
	
	return 0;
}
