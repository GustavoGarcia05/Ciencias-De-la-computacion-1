#include<iostream>
#include <stdio.h>
#include<fstream>
using namespace std;

void escribir (string);

int main (){
	
	escribir ("hola mundo");
	system("pause");
	return 0;
}

void escribir(string info){
	ofstream registro;
	
	registro.open("Registro.txt",ios::out);
	
	if(registro.fail()){
		cout<<"no se pudo abrir el archivo";
		exit (1);
	}
	registro<<info<<endl;
	registro.close();
}
