
using namespace std;

template<class T, class S>
//estructura de tres variables, dos desconocidas y un apuntador a otra estructura (sig) 
struct nodo{
	T dato;//tipo desconocido
	S desc;//tipo desconocido
	nodo<T,S> *sig;//apuntador a estructura
};


template<class T, class S>
//funcion para llenar los dos datos desconocidos de una estructura (nodo)
void llenar(nodo<T,S> *apun, T a, S b){
	
	apun->dato=a;
	apun->desc=b;
}


template<class T, class S>
//Funcion para agrgar nodo y pasarle la direcion del nuevo nodo al tercer campo de la estructura (sig)
void agregarNodo(nodo<T,S> *cabeza,T a, S b ){
	
	nodo<T,S> *aux= new nodo<T,S>;

	llenar(aux,a,b);
	
	aux->sig=cabeza;
	cabeza=aux;
		


	
}


template<class T>
//funcion para imprimir un objeto de cualquier tipo primitivo (int, char, double...) 
void imprimir(T obj){
	
	cout<<obj<<endl;
}

template<class T, class S>
//funcion para imprimir un objeto de cualquier tipo primitivo (int, char, double...) 
void imprimirNodo(nodo<T,S> *nodImp){
	
	cout<<nodImp->dato<<endl;
	cout<<nodImp->desc<<endl;
	cout<<nodImp->sig<<endl;
}
