#include<iostream>
#include<ctime>

using namespace std;
unsigned t0,t1;
int devolverCambio(int);

int main(int argc, char** argv){
	t0=clock();
	int n;
	cout<<"ingrese un valor de cambio ";
	cin>>n;
	devolverCambio(n);
	t1=clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;
	return 0;
}

int devolverCambio(int cambio){
	
	int monedas[]={1000,500,200,100,50,10};
	int s[24];// conjunto de monedas que se entregaran como cambio
	int z=0;// soma de los valores contenidos en s 
	int i=0,j=0,x=0;
	
	while(z!=cambio){
		x=monedas[i];
		if(z+x<=cambio){
			
			s[j]=x;
			z=z+x;
			j++;
		}else{
		i++;
		}	
	}
	for(int k=0;k<j;k++){
		cout<<"la moneda en la posicion "<<k<<" es de :"<<s[k]<<endl;
	}
		
	return z;
}
