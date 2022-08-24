
/*Algoritmo demostrativo del método de ordenación externo: Mezcla equilibrada múltiple

Luisa Torres: / CI: 28676981
Daniel Guarimata / CI: 27301900

*/


#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

	const int N = 6;   //Declaramos como constante la cantidad de archivos
	const int N2 = N/2; // Serán 3 de entrada y 3 de salida
	const int MAXT = 32767; //Valor máximo de tramos

	fstream* f [N];   
	ifstream datos;

	const char* nomf[N] = {"f1", "f2", "f3", "f4","f5","f6"};   //Declaro como constante los nombres de los archivos
	const char* arcPrin = "datos.txt";  //Archivo de donde se leeran los números y serán ordenados
  
	int registro[N2];  //Para guardar los registros
	int c[N], cd[N];
	bool actvs[N];
	
		// Funciones a utilizar
	
	void mezcla();
	int distribuir();
	void leerItems(int r[], int nf, int cd[]);
	int minimo(int r[], bool activo[], int n);
	bool finDeTramos(bool activo[], int n);

	void mezcla()
	{
		int i, j, k, k1, t;
		int anterior;   //Para el registro anterior
		t = distribuir(); //Se realiza la distribución inicial y se obtiene la cantidad de tramos
		for (i = 0; i < N; i++)
			c[i] = i;  //Inicializamos
		
			
		do {   // Bucle principal, termina cuando ya esté ordenado el archivo
            ofstream of(arcPrin, ios::out);
			k1 = (t < N2) ? t : N2;
			/*	if(t<N2) 
				k1 =t;
			else
				k1=N2;*/
		//	k1 += 1;	 // numero de archivos
			k = k1;

			for (i = 0; i < k1; i++)
			{
				f[c[i]] = new fstream( nomf[c[i]],ios::in);
			//	f[c[i]].open(nomf[c[i]],ios::in);
				if (f[c[i]] -> bad())
				{
					throw " Error al abrir archivo";
				}
				cd[i] = c[i];
			}

			t = 0; 			 // Numero de tramos mezclados
			//j = N2 + 1;	 // índice de archivo de salida
				j = N2;
			for (i = j; i < N; i++)
			{
				f[c[i]] = new fstream( nomf[c[i]],ios::out);
		    	//f[c[i]].open(nomf[c[i]],ios::out|ios::trunc);
				if (f[c[i]] -> bad())
				{
					throw " Error al abrir archivo en modo salida";
				}
			}

			leerItems(registro, k1, cd);
			while (k1 > 0)
			{
				t++; 			// mezcla de un nuevo tramo
				for (i = 0; i < k1; i++)  actvs[i] = true;
				while (!finDeTramos(actvs, k))
				{
					int indiceMin;
					indiceMin = minimo(registro, actvs, k);
					(*f[c[j]]) << registro[indiceMin] << " " ;
					of << registro[indiceMin] <<" ";
					anterior = registro[indiceMin];
					(*f[cd[indiceMin]]) >> registro[indiceMin];// lee del mismo flujo

					if (f[cd[indiceMin]]-> eof())	// archivo quedará no activo
					{
						k1--;
						actvs[indiceMin] = false;
						f[cd[indiceMin]]->close();  // archivo cd[] inactivo
						cd[indiceMin] = cd[k1];			//	 cambia contenido de k1
						registro[indiceMin] = registro[k1];			// por el de indiceMin
						actvs[indiceMin] = actvs[k1];
						actvs[k1] =false;		// no se accede a la posición k1
						}
					else
					{
						if (anterior > registro[indiceMin]) 	// fin de tramo
							actvs[indiceMin] = false;
					}
				}
				j = (j < N - 1 ) ? j + 1 : N2 ; // siguiente archivo salida
				}

			for (i = N2; i < N; i++)
			{
				f[c[i]]->close();
			}
				/*
					Cambio en la finalidad de los archivos
				*/
			for (i = 0; i < N2; i++)
			{
				int a;
				a       			= c[i];
				c[i]    			= c[i + N2];
				c[i + N2] = a;
			}
			
        	of.close();// Se cierra el archivo
		} while (t > 1);  //Se cierra el ciclo principal, se repetirá hasta que haya un solo tramo
}

	int distribuir()
	{
		int anterior, j, nt;
		int r;

		datos.open(arcPrin, ios::in);
		if (!datos)
		{
			throw "Error al abrir archivo principal";
		}
		for (j = 0; j <= N2; j++)
		{
			f[j] = new fstream(nomf[j], ios::out);
			if (f[j]->bad())
			{
				throw "Error al abrir archivo auxiliar ";
			}
		}

		anterior = -MAXT; //Se empieza desde el primer valor que se puede tener, según los límites establecidos
		r = anterior + 1;
		j = 0; 		// indice de archivo de salida
		nt = 0;               // Contador para cantidad de tramos
		while (!datos.eof()) //Mientras no haya llegado a su fin el archivo
		{
						// Copia un tramo del archivo principal  al archivo j que se esté trabajando de salida
			while (anterior <= r && !datos.eof())   //Mientras no se haya llegado al final y r sea menor o igual al registro anterior
			{
				datos >> r; //Acceder a los datos con >>
				if (!datos.eof())
					if (anterior <= r)
					{
						(*f[j]) << r << " ";
						anterior = r;
				}

			}
			nt++; 									// Se incrementa el contador de tramos
			j = (j < N2-1) ? j + 1 : 0;	// Se evalúa el siguiente archivo

			if (!datos.eof())  			// Añade nuevo tramo
			{
				(*f[j]) << r << " ";

				anterior = r;
			}
		}
		datos.close();   //Se cierra el archivo
		for (j = 0; j < N2; j++)
			f[j]-> close();     //Se cierran los archivos
		//cout << "\n tramos: " << nt << endl;
		return nt;
	}

	void leerItems(int r[], int nf, int cd[])  
	{
		for (int n = 0; n < nf; n++)
			(*f[cd[n]]) >> r[n];
	}

	int minimo(int r[], bool activo[], int n)
	{
		int i, indice;
		int m;
		i = indice = 0;
		m = MAXT;

		for ( ; i < n; i++)
		{
			if (activo[i] && r[i] < m)
			{
				m = r[i];
				indice = i;
			}
		}
		return indice;
	}

	bool finDeTramos(bool activo[], int n)
	{
		bool s = true;
		for(int k = 0; k < n; k++)
		{
			if (activo[k])	 s = false;
		}
		return s;
	}

int cuentaReg(){
	int k = 0;
	int registro;
	ifstream f(arcPrin);
	while (!f.eof()){
		f >> registro;
		k++;
	}
	f.close();
	return k;
}

int mostrar(string s, int size){
	ifstream entrada(arcPrin, ios::in );
	if(!entrada){
		cout<<"HA OCURRIDO UN ERROR AL ESCRIBIR EN EL ARCHIVO"<<endl;
		return 1;
 	}

	cout<<s;
	
	int reg[size];
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
	int cant=cuentaReg();
	cant-=1;
	mostrar("Antes: ", cant);
	mezcla();
	mostrar("Despues: ", cant);
	cin.get();
	return 0;
}
