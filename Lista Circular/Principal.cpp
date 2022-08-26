/*
*
*UNIVERSIDAD DE ORIENTE
*ASIGNATURA: ESTRUCTURA DE DATOS (SECC. 01)
*
*LISTA CIRCULAR, SUMA DE GRANDES CANTIDADES
*
*/

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "ListaCircular.h"

using namespace std;

int mayor(int a, int b){
	return (a>b)?0:1;
}
string completacion(string numero, int diferencia){
	int mayor=numero.length()+diferencia;                     
	//int diferencia= mayor-size[opc];
		
	for(int i=mayor-1; i>=0; i--){                   //recorro de atras hacia adelante el string para colocar 0 al inicio
		if(i<diferencia){
			numero[i]='0';
		}
		else{
			numero[i]=numero[i-diferencia];
		}
	}
	return numero;
}

void suma(string numero1,string numero2){
	//Declaracion las listas a utilizar
	ListaCircular lista[3];
	
	//Declaracion cantidad de digitos (MAXIMO 50 Digitos)
	int entrada[2][50];
	
	string digito[2];
	//Declaracion de tamaño del array
	int size[2];
	string numero[2];
	numero[0]=numero1 ;
	numero[1]=numero2;
	
	size[0]=numero[0].length();
	size[1]=numero[1].length();
	if(size[0]!=size[1]){              //Si no son del mismo tama;o
		int m=mayor(size[0],size[1]);  //Busco cual tiene mas digitos
		int opc=(m==0)?1:0;
		int diferencia= size[m]-size[opc];  //resto la cantidad de digitos del mayor con el menor
	
		numero[opc]=completacion(numero[opc],diferencia);   //completo el menor con 0 a la izquierda
		size[opc]+=diferencia;                             //como mas adelante se recorre segun el tama;o, aumento manualmente el size del menor

		}
		
		
	//convierte tu cadena a un entero y te muestra el resultado
	for(int i=0; i < size[0]; i++){
		digito[0]=numero[0][i];
		entrada[0][i]=atoi(digito[0].c_str());
	}
	for(int i=0; i < size[1]; i++){
		digito[1]=numero[1][i];
		entrada[1][i]=atoi(digito[1].c_str());
	}
		
		
	//ingresa los numeros obtenidos por el usuario
	for(int i=0; i<size[0]; i++){
		lista[0].insertarUltimo(entrada[0][i]);
	}
		
	for(int i=0; i<size[1]; i++){
		lista[1].insertarUltimo(entrada[1][i]);
	}
		
	for(int i=0; i<size[1]; i++){
		lista[2].sumar(lista[0].infoActual(),lista[1].infoActual());
		//cout<<lista[0].infoActual()+lista[1].infoActual()<<"   ";
		lista[0].borrar(1);
		lista[1].borrar(1);
	}
		
	lista[2].verificarSuma();
		
	lista[2].mostrar();
}
		
		

	

int main()
{
    //Declaracion de variables en string
    string numero1,numero2;
	int size1,size2;
    //pide y guarda los valores como una cadena
    cout<<"Hey!\n"<<endl;
	char resp;
    do{
	do{
        cout<<"\n Aqui le ayudaremos a sumar cantidades grandes :) \n Estas deben ser mayores a 30 digitos y menores que 50 Digitos\n"<<endl;
	    cout << "Ingrese la primera cantidad a sumar:" << endl;
	    cin >> numero1;
	    cout << "Ingrese la segunda cantidad a sumar:" << endl;
	    cin >> numero2;

		size1=numero1.length();
		size2=numero2.length();
	}while(size1<30||size2<30||size1>50||size2>50);
	cout<<"Fabuloso, el resultado de tu suma es: "<<endl; suma(numero1,numero2);
	getch();
	cout << "Ingrese 'S' si desea volver a intentar" << endl;
	cin >>resp;
	}while(resp=='S'||resp=='s');
	cout <<"Feliz dia ;)";
	getch();
	return 0;
}

