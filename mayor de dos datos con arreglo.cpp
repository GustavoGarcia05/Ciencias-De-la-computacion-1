#include <iostream>
#include<stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int n, k, may=0,peso=0;
	cin>>n;
	int *dato;
	dato= new int[n];
	
	for(k=0;k<n;k++){
	dato[k]=rand();
	peso=peso+sizeof(dato[k]);
	}
	
	
	may=dato[0];
	for(k=1;k<n;k++)
	if(dato[k]>may){
	may=dato[k];
	}
	
	cout<<" este es el dato mayor"<<may<<endl;
	peso=peso+sizeof(n)+sizeof(k)+sizeof(may);
	cout<<"el peso total es "<<peso;
	return 0;
}
