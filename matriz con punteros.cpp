#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N,i,peso=0;

struct nodo {
    int x,y;
    nodo *sig;
};


int main(int argc, char** argv) {
    nodo *cab=NULL,*aux;
    cout<<"ingrese el numero de datos: ";
    cin>> N;

    for(i=0; i<N; i++) {
        aux= new nodo;
        aux->x=i;
        aux->y=N-i;
        aux->sig= cab;
        cab=aux;
        peso=peso +sizeof(aux->x)+sizeof(aux->y)+sizeof(aux->sig);
        
    }

    while(aux!=NULL) {
        cout<<aux->x<<" "<<aux->y<<endl;
        aux=aux->sig;
    }
    peso+= sizeof(N)+sizeof(i)+sizeof(cab);
    cout<<"el peso total es: "<<peso<<endl;

    for(aux=cab->sig; aux!=NULL; aux->sig) {
        delete cab;
        cab=aux;
    }

    delete cab;


    return 0;
}
