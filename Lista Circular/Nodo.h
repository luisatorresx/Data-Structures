
//CLASE NODO
class Nodo {
	public:
		int info;
		Nodo* sig;
		Nodo* ant;
		Nodo(int datoNuevo, Nodo *enlaceNuevo=NULL){
			info = datoNuevo;
			sig = enlaceNuevo;
		}
		Nodo(){
			sig = NULL;
		}
};
