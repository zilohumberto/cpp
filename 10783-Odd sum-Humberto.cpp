#include <iostream>
using namespace std;

int main() {
	int a,b,c,i=1;
	cin>>c;
	while(c--){

		cin>>a>>b;
		int aux=b,cont=0;
		if(aux%2==1){ cont=b;}else{cont=b;  aux--; }
		while(aux>=a){
			aux = aux/2;
			cont+=aux;
		}
		cout<<"Case "<<i++<<": "<<cont<<endl;
	}
	return 0;
}
