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
int DIMENSION;
bool colocarReina (int **t, int fila);
void imprimir(int **lab);
void contarAlgoritmo(int **t);
bool amenazada(int **t, int fila, int columna);
double contador(LARGE_INTEGER *a ,LARGE_INTEGER *b);

ofstream registro;

int main(int argc, char *argv[])
{
		int**t,i,j;
		
		
		registro.open("Registro.txt",ios::out);
		
		if(registro.fail()){
		cout<<"no se pudo abrir el archivo";
		exit (1);
	}
		
		for (DIMENSION=31;DIMENSION<=50;DIMENSION++)
		{
			t=new int*[DIMENSION];			//Crear arreglo
			for (i=0; i<DIMENSION;i++)
				t[i]=new int[DIMENSION];
			for(i=0;i<DIMENSION;i++)		//Rellenado de arreglo
				for(j=0;j<DIMENSION;j++)
					t[i][j]=0;
			contarAlgoritmo(t);
			//imprimir(t);					//IMPRIME EL TABLERO CON LA REINAS SEGUN SU ORDEN DE COLOCACION
		}
		
		registro.close();
		delete(registro);
		system("PAUSE");
		return EXIT_SUCCESS;	
}

void contarAlgoritmo(int **t)
{
	LARGE_INTEGER t_ini ,t_fin;
    double secs, aux;
    //inicio del proceso que se desea medir
    QueryPerformanceCounter(&t_ini);
    //--------------------------------
  	colocarReina(t,0);
    //--------------------------------
    QueryPerformanceCounter(&t_fin);
    //finalicacion del proceso que se desa medir
    secs= contador(&t_fin,&t_ini);
    
    aux =secs * 1000.0;
    printf("%.16g milisegundos\n", aux);
    registro<<aux<<endl;
    cout<<DIMENSION<<") --------------------"<<endl;
}

double contador(LARGE_INTEGER *a ,LARGE_INTEGER *b) 
{
    //cout<<"aqui corre contador"<<endl;
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


bool colocarReina(int **t, int fila)
{
	bool tmp;
	for(int columna=0;columna<DIMENSION;columna++)
	{
		if(fila == DIMENSION)
    		return true;
		if (!amenazada(t, fila, columna))
		{
       		t[fila][columna]= fila + 1; // reina i-esima
       		tmp= colocarReina(t, fila+1);
       		if (tmp==true) return true;
       		//borra soluci?n invalida
       		t[fila][columna]=0;
    	}
 	}
 	return false;
}

void imprimir(int **lab)
{
	for (int i =0; i<DIMENSION; i++)
    {
		for (int j =0; j<DIMENSION; j++)
        	cout<<" "<<lab[i][j];
     	cout<<endl;
    }
}

bool amenazada(int **t, int fila, int columna)
{
	int i,f,c;
	// revisa fila y columna
	for (i=0; i< DIMENSION; i++)
  	{
		if(t[fila][i] != 0 || t[i][columna] !=0) 
			return true;
  	}

	// arriba a la izquierda  
 	for (f=fila, c=columna; f>=0&& c>=0; f--,c--)
 	{
		if(t[f][c] !=0 ) 
			return true;
 	}  
 	//arriba a la derecha
 	for (f=fila, c=columna; f>=0&& c<DIMENSION; f--,c++) 
 	{
		if(t[f][c]!=0) 
			return true; 
 	}
 	//abajo a la izquierda
 	for (f=fila, c=columna; f<DIMENSION&& c>=0; f++,c--)
	{
		if(t[f][c]!=0) 
			return true;
	}
	//abajo derecha
	for (f=fila, c=columna; f<DIMENSION&& c<DIMENSION; f++,c++)
	{
		if(t[f][c]!=0) 
			return true;}

	return false;
}
