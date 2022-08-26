/*Asignaci�n 5.
Uso de cola con arreglo circular para determinar si un n�mero es capic�a

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
		//Se crea la cola vac�a
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
		cout<<"Ingrese el n�mero a evaluar, este debe tener m�ximo 10 d�gitos :)"<<endl;
		cin>>elem;
		
		//Se llenan la pila y la cola con el n�mero
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
			cout<<elem<<" es capic�a :)"<<endl;
		}else
		   cout<<elem<<" no es capic�a."<<endl;	
		cout<<endl<<endl<<"Presiona S si deseas evaluar otra expresi�n :)"<<endl;
		cin>>resp;
	} while(resp=='S'||resp=='s');
	cout<<"Fue un placer ayudarte :)";
	
	return 0;
}
