
/*Algoritmo demostrativo del método de ordenación externo: Mezcla equilibrada múltiple


*/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

char nomOrigen[]="datos.txt";

// Conocer cantidad de registros
int cantidadR(char nombrea[]){
	int c = 0;
	int registro;
	ifstream a(nombrea);
	while (!a.eof()){
		a>> registro;   //Acceder a los datos
		c++;
	}
	a.close();
	return c;
}

// Función que realiza la mezcla
void mezclar(char nf1[], char nf2[], char nf[], int& lonSec, int numReg){
	int numSec, resto, i, j, k;
	int reg1, reg2;
	numSec = numReg /(2 * lonSec); // número de subsecuencias
	resto = numReg %(2 * lonSec);
	ofstream f(nf);
	ifstream f1(nf1);
	ifstream f2(nf2);
	f1 >> reg1;
	f2 >> reg2;
	for (int s = 1; s <= numSec + 1; s++){
		int n1, n2;
		n1 = n2 = lonSec;
		if (s == numSec+1){ // Proceso de los registros de la subsecuencia incompleta
			if (resto > lonSec)
				n2 = resto - lonSec;
			else{
				n1 = resto;
				n2 = 0;
			}
		}
		i = j = 1;
		while (i <= n1 && j <= n2){
			int actual;
			if (reg1 < reg2){
				actual = reg1;
				f1 >> reg1;
				i++;
			}
			else{
				actual = reg2;
				f2 >> reg2;
				j++;
			}
			f << actual <<" ";
		}

		for (k = i; k <= n1; k++){
			f << reg1 <<" ";
			f1 >> reg1;
		}
		for (k = j; k <= n2; k++){
			f << reg2 <<" ";
			f2 >> reg2;
		}
	}
	lonSec *= 2;
	f.close(); f1.close();f2.close();
}


// lee de f una secuencia y la escribe en t
void subSecuencia(ifstream &f, ofstream &t, int longSec){
	for (int j = 1; j <= longSec; j++){
		int reg;
		f >> reg; // lee del archivo asociado a f
		t << reg <<" "; // escribe en archivo asociado a t
	}
}


// función que separa secuencias ordenadas de registros
void separar(char *nfa, char *nf1, char *nf2, int lonSec, int numReg){
	int numSec, resto, i;
	numSec = numReg /(2*lonSec);
	resto = numReg %(2*lonSec);
	ifstream f(nfa);
	ofstream f1(nf1);
	ofstream f2(nf2);
	if (f.bad()||f1.bad()||f2.bad())
		throw " Error en el proceso de separación ";
	for (i = 1; i <= numSec; i++){
		subSecuencia(f, f1, lonSec);
		subSecuencia(f, f2, lonSec);
	}

//Se procesa el resto de registros del archivo

	if (resto > lonSec)
		resto -= lonSec;
	else{
		lonSec = resto;
		resto = 0;
	}
	subSecuencia(f, f1, lonSec);
	subSecuencia(f, f2, resto);
	f1.close(); f2.close(); f.close();
}


// función que controla el algoritmo de ordenación
void mezclaDirecta(char f[]){
	int longSec;
	int numReg;
	char f1[]= "f1";
	char f2[]= "f2";
	numReg =cantidadR(f); // Llamamos a la función que nos devuelve la cantidad de registros
	longSec = 1;
	while (longSec < numReg){
		separar(f, f1, f2, longSec, numReg);
		mezclar(f1, f2, f, longSec, numReg);
	}
}

int mostrar(string s){
	ifstream entrada(nomOrigen, ios::in );
	if(!entrada){
		cout<<"HA OCURRIDO UN ERROR AL ESCRIBIR EN EL ARCHIVO"<<endl;
		return 1;
 	}
	cout<<s;
	int size=cantidadR(nomOrigen);
	int reg[size];

	size-=1;
	for(int i=0; i<size; i++){
		entrada>>reg[i];
 	}

	for (int i=0; i<size; i++){
		cout<<reg[i]<<" ";
	}
	entrada.close();
	return 0;
}

// muestra el archivo antes y despues
int mostrar(string s, int size){
    int reg[size];
    
	ifstream entrada(nomOrigen, ios::in );
	if(!entrada){
		cout<<"HA OCURRIDO UN ERROR AL ESCRIBIR EN EL ARCHIVO"<<endl;
		return 1;
 	}
 	
	cout<<s;//MUESTRA EL STRING RECIBIDO
	for(int i=0; i<size; i++){
		entrada>>reg[i];
 	}

	for (int i=0; i<size; i++){
		cout<<reg[i]<<" ";
	}
	cout<<endl;
	entrada.close();
	return 0;
}


int main(){
    int cant=cantidadR(nomOrigen);
	mostrar("Antes: ", cant);
	mezclaDirecta(nomOrigen);
	mostrar("Despues: ", cant);
	cin.get();
return 0;
}

