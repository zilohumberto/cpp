#include <iostream>
#include <math.h>
using namespace std;

void movTorres(int n,int  origen, int destino, int aux){
	if(n>1){
		cout<<"Paso de"<<origen<<" a "<<destino<<endl;
	}else{
		movTorres(n-1,origen,aux,destino);
		cout<<"Paso de "<<origen<<" a "<<destino<<endl;
		movTorres(n-1,aux,destino,origen);
	}
}
int main() {
	short n=0;
	cin>>n;
	cout<<"tiempo (2^n -1): "<<(int)pow(2,n)-1<<endl;
	movTorres(n,1,2,3);
	return 0;
}
