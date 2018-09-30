#include <cstdlib>
#include<iostream>
#include <stdio.h>
#include <windows.h>
#include<fstream>

/* credo por 
dannyr gustavo garcia cardozo 20152020222
sergio duvan nuñez sanchez 20161020133
*/

using namespace std;
int Discos;

ofstream registroHanoi;

void Mover_Torres(int N, int Origen,int Intermedio, int Destino)
{
	
	if (N>1)
	{
		Mover_Torres(N-1, Origen,Destino, Intermedio);
		Mover_Torres(N-1, Intermedio,Origen,Destino );
	}
}

double contador(LARGE_INTEGER *a ,LARGE_INTEGER *b) 
{
    //cout<<"aqui corre contador"<<endl;
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

void contarAlgoritmo()
{
	LARGE_INTEGER t_ini ,t_fin;
    float secs, aux;
    //inicio del proceso que se desea medir
    QueryPerformanceCounter(&t_ini);
    //--------------------------------
  	Mover_Torres(Discos, 1, 2, 3);
    //--------------------------------
    QueryPerformanceCounter(&t_fin);
    //finalicacion del proceso que se desa medir
    secs= contador(&t_fin,&t_ini);
     aux =secs * 1000.0;
    printf("%.16g milisegundos\n", aux);
    
     registroHanoi<<aux<<endl;
    cout<<"--------------------"<<endl;
}

int main(int argc, char *argv[])
{
registroHanoi.open("Registro.txt",ios::out);

	for(Discos=3;Discos<100; Discos++)
	{
		cout << "El numero de discos es: "<<Discos<<endl;
		contarAlgoritmo();
    }
    registroHanoi.close();
    delete(registroHanoi);
	system("PAUSE");
    return EXIT_SUCCESS;
}

