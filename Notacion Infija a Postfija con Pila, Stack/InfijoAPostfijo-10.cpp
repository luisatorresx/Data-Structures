/*Asignaci�n 4.
Transformaci�n de notaci�n infija a postfija
*/

#include <iostream>
#include <string.h>
#include "PilaT.h"
using namespace std;

//Retorna un valor espec�fico para cada operador, de esta forma evaluamos la prioridad. Mientras mayor sea el n�mero, mayor prioridad tiene.
int prioridad(char c) {
	if(c == '^')          //Potencia
		return 3;
	else if(c == '/' || c=='*') //Divisi�n o multiplicaci�n
		return 2;
	else if(c == '+' || c == '-')  //Suma o resta
		return 1;
	else
		return -1; //no es ninguno de los establecidos 
}

// Funci�n principal, pasa la notaci�n infija a postfija

void convierteAPost(string s) {
	
	PilaT<char> operadores; // Declaraci�n de la pila, creando una pila template de char. Esta es para almacenar los operadores
	char *postfija= new char[s.length()] ;
	int j=0;                 //Uso este contador para el indice del arreglo del resultado de la expresi�n postfija 
	for(int i = 0; i < s.length(); i++) {  //For principal, este recorre la expresi�n que fue ingresada en notaci�n infija caracter a caracter
		char c = s[i];
		
		
		// Si el caracter es un operando, simplemente se a�ade al arreglo. Toma en cuenta caracteres en may�scula, min�scula y n�meros 
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) 
			postfija[j++]= c;                                                          //Se aumenta el contador del indice del resultado
		
		// Si el caracter es par�ntesis que abre '(', lo a�ade a la pila
		else if(c == '(')
			operadores.insertar('(');
		
		
		else if(c == ')') {                     // Si el caracter es par�ntesis que cierra �)�
			while(operadores.cimaPila() != '(') //, se vac�a la pila y se van incluyendo los operadores al arreglo hasta que encuentre '(' en la pila
			{
				postfija[j++]= operadores.cimaPila();           //Aqu� se van a�adiendo al arreglo 
				operadores.quitar();                         
			}
			operadores.quitar();                             //Al salir del while, el caracter posicionado es '(' por lo que se borra de la pila.
		}
		
		// En cualquier otro caso, el caracter se considerar� un operador
		else {
			if(prioridad(c)==-1){ //Si prioridad da -1, es porque el car�cter no forma parte de los admitidos y considerados como operadores.
				cout<<"Ha ingresado un car�cter inv�lido:"<<c<<endl;
				break;
			}
			if(i==s.length()-1 && prioridad(c)>=1){ //Si est� en el final de la expresi�n recibida, y es un operador, quiere decir que no est� completa
				cout<<"Ha ingresado una expresi�n incompleta, debe colocar un operando despu�s de "<<c<<endl; 
				break;}
			   else{        //En caso contrario, procede a evaluarses.
				
			//se hace un llamado a la funci�n prioridad,y compara la del caracter con la de la cima de la pila. Si es de menor o igual prioridad, contin�a
				while(!operadores.pilaVacia() && prioridad(c) <= prioridad(operadores.cimaPila())) {  
					postfija[j++]= operadores.cimaPila(); //Se saca el elemento de la cima de la pila, se pone en el arreglo y se vuelve a hacer la comparaci�n
					operadores.quitar(); 
				}
			
			operadores.insertar(c);  //En este caso,al no entrar en el while por ser mayor, se a�ade a la pila. Tambi�n se a�adir� si la pila est� vac�a.
			}
		}
	}
	
	// Se sacan el resto de operadores de la pila, si no est� vac�a
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
	cout<<"�Hola! Aqu� pasaremos expresiones en Notaci�n Infija, as� como: (a+b)"<<endl<<"a Notaci�n Postfija, como: ab+"<<endl;
	cout<<"Recuerda que los operadores v�lidos son:"<<endl<<"'^' Potencia "<<endl<<"'*' Multiplicaci�n "<<endl<<"'/' Divisi�n"<<endl<<"'+' Suma"<<endl<<"'-' Resta"
		<<endl<< "Adem�s de '(' y ')' para indicar orden de evaluaci�n :)"<<endl<<endl<<"Primera expresi�n a transfornar:"<<exp<<endl;
	do{
		if(uso){
			cout<<"Ingresa la expresi�n a transformar: "<<endl;
			cin>>exp;
		}
		cout<<"Notaci�n Postfija: "; convierteAPost(exp);
		cout<<endl<<endl<<"�Deseas transformar otra expresi�n?"<<endl<<"[S]S� \t [N]No"<<endl;
		cin>>resp;
		uso=true;
	} while(resp=='S'||resp=='s');
	cout<<endl<<endl<<"Gracias por usarme ;)"<<endl;
	return 0;
}
