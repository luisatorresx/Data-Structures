/*Asignación 4.
Transformación de notación infija a postfija
*/

#include <iostream>
#include <string.h>
#include "PilaT.h"
using namespace std;

//Retorna un valor específico para cada operador, de esta forma evaluamos la prioridad. Mientras mayor sea el número, mayor prioridad tiene.
int prioridad(char c) {
	if(c == '^')          //Potencia
		return 3;
	else if(c == '/' || c=='*') //División o multiplicación
		return 2;
	else if(c == '+' || c == '-')  //Suma o resta
		return 1;
	else
		return -1; //no es ninguno de los establecidos 
}

// Función principal, pasa la notación infija a postfija

void convierteAPost(string s) {
	
	PilaT<char> operadores; // Declaración de la pila, creando una pila template de char. Esta es para almacenar los operadores
	char *postfija= new char[s.length()] ;
	int j=0;                 //Uso este contador para el indice del arreglo del resultado de la expresión postfija 
	for(int i = 0; i < s.length(); i++) {  //For principal, este recorre la expresión que fue ingresada en notación infija caracter a caracter
		char c = s[i];
		
		
		// Si el caracter es un operando, simplemente se añade al arreglo. Toma en cuenta caracteres en mayúscula, minúscula y números 
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) 
			postfija[j++]= c;                                                          //Se aumenta el contador del indice del resultado
		
		// Si el caracter es paréntesis que abre '(', lo añade a la pila
		else if(c == '(')
			operadores.insertar('(');
		
		
		else if(c == ')') {                     // Si el caracter es paréntesis que cierra ‘)’
			while(operadores.cimaPila() != '(') //, se vacía la pila y se van incluyendo los operadores al arreglo hasta que encuentre '(' en la pila
			{
				postfija[j++]= operadores.cimaPila();           //Aquí se van añadiendo al arreglo 
				operadores.quitar();                         
			}
			operadores.quitar();                             //Al salir del while, el caracter posicionado es '(' por lo que se borra de la pila.
		}
		
		// En cualquier otro caso, el caracter se considerará un operador
		else {
			if(prioridad(c)==-1){ //Si prioridad da -1, es porque el carácter no forma parte de los admitidos y considerados como operadores.
				cout<<"Ha ingresado un carácter inválido:"<<c<<endl;
				break;
			}
			if(i==s.length()-1 && prioridad(c)>=1){ //Si está en el final de la expresión recibida, y es un operador, quiere decir que no está completa
				cout<<"Ha ingresado una expresión incompleta, debe colocar un operando después de "<<c<<endl; 
				break;}
			   else{        //En caso contrario, procede a evaluarses.
				
			//se hace un llamado a la función prioridad,y compara la del caracter con la de la cima de la pila. Si es de menor o igual prioridad, continúa
				while(!operadores.pilaVacia() && prioridad(c) <= prioridad(operadores.cimaPila())) {  
					postfija[j++]= operadores.cimaPila(); //Se saca el elemento de la cima de la pila, se pone en el arreglo y se vuelve a hacer la comparación
					operadores.quitar(); 
				}
			
			operadores.insertar(c);  //En este caso,al no entrar en el while por ser mayor, se añade a la pila. También se añadirá si la pila está vacía.
			}
		}
	}
	
	// Se sacan el resto de operadores de la pila, si no está vacía
	while(!operadores.pilaVacia()) {
		postfija[j++]= operadores.cimaPila();
		operadores.quitar();
	}
	for(int i = 0; i <j; i++)  //Se muestra el resultado.
		cout << postfija[i];

	delete[] postfija;
}

//Main 
int main() {
	string exp = "a*(b+c-(d/e^f)-g)-h";
 bool uso=false;          
	char resp;
	//Una guia instructiva basica de como pasar de notacion Infija a Postfija
	cout<<"¡Hola! Aquí pasaremos expresiones en Notación Infija, así como: (a+b)"<<endl<<"a Notación Postfija, como: ab+"<<endl;
	cout<<"Recuerda que los operadores válidos son:"<<endl<<"'^' Potencia "<<endl<<"'*' Multiplicación "<<endl<<"'/' División"<<endl<<"'+' Suma"<<endl<<"'-' Resta"
		<<endl<< "Además de '(' y ')' para indicar orden de evaluación :)"<<endl<<endl<<"Primera expresión a transfornar:"<<exp<<endl;
	do{
		if(uso){
			cout<<"Ingresa la expresión a transformar: "<<endl;
			cin>>exp;
		}
		cout<<"Notación Postfija: "; convierteAPost(exp);
		cout<<endl<<endl<<"¿Deseas transformar otra expresión?"<<endl<<"[S]Sí \t [N]No"<<endl;
		cin>>resp;
		uso=true;
	} while(resp=='S'||resp=='s');
	cout<<endl<<endl<<"Gracias por usarme ;)"<<endl;
	return 0;
}
