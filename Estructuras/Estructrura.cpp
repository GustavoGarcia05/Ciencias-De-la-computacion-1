#include<iostream>
#include "Biblioteca.h"

using namespace std;

int main(){
		
	nodo<int,char> prueba, pru,*cab = NULL;
	cab=&prueba;
	
	llenar(cab,3,'Q');
	prueba.sig=NULL;
	imprimirNodo(cab);
	
	llenar(&pru,6,'K');
	pru.sig=cab;
	imprimirNodo(&pru);

	system("pause");
	return 0;
}
