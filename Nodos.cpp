#include <iostream>
using namespace std;

class nodo{
	public:
		string nombre,apellido;
		nodo *sig, *ant;
		nodo(){
			sig=NULL;
			ant=NULL;
		}
		nodo(string nb, string ap){
			nombre=nb;
			apellido=ap;
			sig=ant=NULL;
		}
};

struct nodo2{
	int peso;
	struct nodo *sig;
};
int main() {
	//nodo2 *l;
	nodo2 *p;
	nodo *lista[2];
	nodo *a= new nodo("humberto","rodriguez");
	lista[0]=a;
	nodo *b= new nodo("rodriguez","humberto");
	lista[1]= b;
	for(int i=0;i<2;i++){
		cout <<lista[i]->nombre << " - "<<lista[i]->apellido<<endl;
	}
	return 0;
}
