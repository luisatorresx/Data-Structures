/*
7.	Determinar la lista enlazada m�s larga (mayor n�mero de nodos) cuando se utiliza 
una tabla hash enlazada para guardar 1.000 n�meros enteros generados aleatoriamente. 
Escribir un programa que realice la tarea propuesta, considerar que el factor de carga es 1.


Si factor de carga= 1 y n�mero de elementos= 1.000
entonces, el tama�o de la tabla debe ser 1.000
*/


#include <iostream>
#include <math.h>
using namespace std;

const int m=1000;        //Tama�o de la tabla

//Clase Elemento, funciona como nodo 
class Elemento{
	protected:
    	int numero;         
    	Elemento *enlace;

	public:
    	Elemento(int num){   //Constructor del nodo 
	        numero = num;
	        enlace = NULL;
    	}
    	Elemento *getEnlace() {
			return enlace; 
		}
		void setEnlace(Elemento *enl){
			enlace = enl;
		}
    	int getNumero(){
			return numero;
		}
    	void setNumero(int num){
			numero=num;
		}
};

//Clase de Tabla Hash 
class TablaHash{
	protected:
        Elemento **tabla;
	    int final;
	    int *tamano;
	    int numElementos;

	public:
	    TablaHash(int m){                   //Constructor, entra el tama�o del que se desea crear
			tabla = new Elemento*[m];   
			tamano = new int[m];			//Final guardar� el tama�o de la lista
			final = m;
			for (int i = 0; i < final; i++){   
				tabla[i] = NULL;
				tamano[i] = 0;              //Este tama�o es el de las listas internas
			}
			numElementos = 0;
		}
	    Elemento *buscar(int clave){
			Elemento *pr;
			int posicion = direccion(clave);
			pr = tabla[posicion];
			if (pr != NULL){
				while ((pr->getEnlace() != NULL) && pr->getNumero() != clave) 
					pr = pr->getEnlace();//Para recorrer la lista interna en la pos
				if (pr->getNumero() != clave)
					pr = NULL;
			}
			return pr;
		}
			
	    bool insertar(Elemento x){    
			Elemento *nuevo, *claveExiste;
			int i=direccion(x.getNumero()); //La posici�n se obtendr� al aplicar la dispersi�n al n�mero
			claveExiste = buscar(x.getNumero());   
			
			//Si la clave no existe, entonces se agrega el elemento a la tabla
			if (!claveExiste){    
				nuevo = new Elemento(x.getNumero());   //Se a�ade al inicio de la lista 
				nuevo->setEnlace(tabla[i]);             //Enlaza nuevo con el primero
				tabla[i] = nuevo;                       //Mueve primero y queda nuevo apuntando al primero
				tamano[i]++; numElementos++;

				return true;   //Retorna true si se pudo a�adir
			}
			else
				
				return false;  //Retorna false si no se pudo a�adir
		}

	    int listaMayor(){
			int mayor=0;
			for(int i = 0; i < final; i++)
				if(tamano[i] > mayor)
				mayor = tamano[i];
			return mayor;
		}
		float factorDeCarga(){
			//cout<<numElementos;
			float factor = (float)numElementos/final;
			return factor;
		}
	private:
	    int direccion(int x){
			return x % final;
		}
};


//Numeros Aleatorios
void numerosAleatorios(int m){
	TablaHash tabla(m);
    int num;

    for (int i = 0; i < m; i++){
        num = rand(); //N�meros aleatorios
		
        if(!tabla.insertar(num))   // Si no se pudo a�adir por estar repetido
			--i;		//Se disminuye el contador, para garantizar que se a�adan los 1.000 elementos
    }
    cout <<"--Factor de carga: "<<tabla.factorDeCarga()<<endl;
	cout <<"--Lista m�s grande: "<<tabla.listaMayor()<<endl;
}

//Menu
void menu(){
	bool bandera=true;
	int opc;
	cout<<"Bienvenido! puede generar 1.000 valores aleatorios \nY saber en cual posici�n se encuentra la lista enlazada ms larga\n"<<endl;
	do{
		cout<<"\n1. Generar n�meros aleatorios"<<endl;
		cout<<"2. Salir\n"<<endl;
		cin>>opc;
		switch(opc){
			case 1: numerosAleatorios(m); break;   //Aqu� entra la constante global
			case 2: bandera=false; break;
		}
	}while(bandera);
	cout<<"Hasta luego."<<endl;
}

//Main
int main(){
	menu();
	return 0;
}

