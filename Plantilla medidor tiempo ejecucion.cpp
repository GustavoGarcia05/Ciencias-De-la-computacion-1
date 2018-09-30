#include<iostream>
#include <stdio.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void generadorArreglos(int,int );
double contador(LARGE_INTEGER *a ,LARGE_INTEGER *b);
void quickSort(int a[],int izq,int der);

int t=0,p=0;
int main(int argc, char** argv) {

    /*cout<<"digite el numero de datos y el paso etre numero y numero"<<endl;
    cin>>t;
    cin>>p;*/
    for(int i=0;i<20;i++){
    	t=50*(i+1);
    	p=10*(i+1);
    	generadorArreglos(t,p);
	}
    
    return 0;
}

void generadorArreglos(int tamanio,int paso) {
   // cout<<"aqui corre generadorArreglos"<<endl;
    int arreglo[tamanio];
    for(int i=0; i<tamanio; i++) {
        arreglo[tamanio-i]=i*paso;
    }
    arreglo[0]=paso*tamanio;

    //--------------------------------------------


    LARGE_INTEGER t_ini ,t_fin;
    double secs;
    cout<<"n= "<<t<<endl;
   
    //inicio del proceso que se desea medir
    QueryPerformanceCounter(&t_ini);
    //--------------------------------

    quickSort(arreglo,0,sizeof(arreglo)/sizeof(*arreglo));


    //--------------------------------
    QueryPerformanceCounter(&t_fin);
    //finalicacion del proceso que se desa medir

    secs= contador(&t_fin,&t_ini);
    printf("%.16g milisegundos\n", secs * 1000.0);
     cout<<"--------------------"<<endl;

    //--------------------------------------------

}

//Funciones complementarias

double contador(LARGE_INTEGER *a ,LARGE_INTEGER *b) {
    //cout<<"aqui corre contador"<<endl;
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;

}


// Funciones del programa

void quickSort(int a[],int izq,int der){
	int i, j, v; //v = pibote
	if(der>izq){
		v=a[der];
		i=izq-1;
		j=der;
		
		for(;;){
			while(a[++i]<v);
			while(a[--j]>v);
			if(i>=j) break;
			a[i]=a[j];
		}
		a[i]=a[der];
		quickSort(a,izq,i-1);
		quickSort(a,i+1,der);
	}
}

