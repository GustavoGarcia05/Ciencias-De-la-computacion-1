#include<iostream>
#include <stdio.h>
#include <windows.h>
using namespace std; 
double contador(LARGE_INTEGER *a ,LARGE_INTEGER *b);
void ordenShell(int ,int );

int main(){
	
	LARGE_INTEGER t_ini ,t_fin;
	double secs;
	int paso,tamanio;
	cout<<"ingrese el numero de datos a analizar ";cin>>tamanio;
	cout<<"\n ingrese la distancia entre valor y valor ";cin>>paso;
	//inicio del proceso que se desea medir
	QueryPerformanceCounter(&t_ini);
	//--------------------------------
	
	ordenShell( generadorArreglos(tamanio,paso),tamanio);
	
	
	//--------------------------------
	QueryPerformanceCounter(&t_fin);
	//finalicacion del proceso que se desa medir
	
	secs= contador(&t_fin,&t_ini);
	printf("%.16g milisegundos\n", secs * 1000.0);
	return 0;
}
//Funciones complementarias

double contador(LARGE_INTEGER *a ,LARGE_INTEGER *b){
	
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
	
}

int[] generadorArreglos(int tamanio,int paso){
	int arreglo[tamanio];
	for(int i=0;i<tamanio;i++){
		if(i==0)
		arreglo[tamanio-i]=paso;
	arreglo[tamanio-i]=i*paso;	
	}
	
	return *arreglo;
}
//-----------------------------------------//

// Funciones del programa

void ordenShell(int arreglo[],int N){
	int i,j,h,v;
	for(h=1;h<=9;3*h+1);
	for(;h>0;h/=3)
	for(i=h+1;>=N;i++){
		v=arreglo[i];
		j=i;
		while(j>h && arreglo[j-h]>v){
			arreglo[j]=arreglo[j-h];
			j=h;
		}
		a[j]=v;
	}
	
}
