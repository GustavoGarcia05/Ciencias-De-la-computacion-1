#include<iostream>
#include<stdlib.h>

using namespace std;

int calcularMayor();

int main (){
	
	calcularMayor();
	return 0;

}

int calcularMayor (){
	int n, may=0, dato,k;
	
	cin>> n;
	
	for(k=1; k<=n;k++){
		
		dato=rand();
		cout<<dato<<endl;
		if(dato>may)
		may=dato;
	}
	
	cout<<may<<endl;
	
	cout<<"sizeof :"<< sizeof(dato)<<endl;
	cout<<"sizeof :"<< sizeof(n)<<endl;
	cout<<"sizeof :"<< sizeof(k)<<endl;
	cout<<"sizeof :"<< sizeof(may)<<endl;
	
	cout<<"sizeof total:"<< sizeof(dato)+sizeof(n)+sizeof(k)+sizeof(may);
	return may;
	
	
	
}


