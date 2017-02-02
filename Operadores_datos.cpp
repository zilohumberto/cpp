#include <iostream>
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)

using namespace std;

int main() {
	//¡operador condicional!
	bool b=false;
	bool a=true;
	a= b==a ? true : false;
	// a = false;
	int i=0;
	if(!a)
		++i;
	if(i>0)
		a=!a;
	else
		b=false;

	switch(i){
				case 1: ++i;
				case 2: i=0; break;
				default: i=100;
	}

	for(short j=0; j<10;j+=2){
		//if(j%2) cout<<"Algo hicistes mal "<<j<<endl;
		//else cout<<"J= "<<j<<endl;
	}
	//#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
	FOR(j,0,10)
		j=j+1-1;
		//if(j%2) cout<<"Algo hicistes mal "<<j<<endl;
		//else  cout<<"J= "<<j<<endl;

	int j=10;
	while(j>0){
		//cout<<"J= "<<j<<endl;
		j-=2;
	}
	do{
		//cout<<"J= "<<j<<endl;
		j+=2;
	}while(j<10);

	//operadores binarios
	//desplazamiento
	int ii = 5; //en binario es 0101
	int jj = ii<<1; //ahora es  1010
	//jj = jj<<2; // jj es 40 base 10 y en base 2  0010 1000
	//cout<< jj<<endl;
	// or bit a bit
	int cc = ii |= jj;
	//cout << cc << endl; //cc es igual a 15 1111 y ii tambien
	// and bit a bit
	cc = ii &= jj;
	//cout << cc << endl; //cc es igual a 10 porque ii= 1111 and jj=1010 y ii tambien
	// or bit a bit
	cc = ii ^= jj;
	//cout << cc << endl; //
	return 0;
}
