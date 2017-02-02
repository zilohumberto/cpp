#include <iostream>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i;i++)
#define SIZE 10000
char h[SIZE][SIZE];
int maxHouse(int m){
	int salida=0;
	FOR(t,0,m){
		FOR(s,0,m){
			if(h[t][s]=='.'){
				int cont=0,ii=0;
				FOR(i,s,m){
					if(h[t][i]=='.'){
						ii=i;
						cont++;
					}else{
						break;
					}
				}
				if(ii>= s){
					cout<<ii<<endl;
					int aux=0;
					FOR(i,0,ii){
						FOR(j,0,ii){
							if(h[i][j]=='#'){
								break;
							}
						}
						aux++;
					}
					salida=max(salida,aux);
				}
			}
		}
	}
	return salida;
}
int main() {
	int n;
	cin>>n;
	while(n-->0){
		int m=0;
		cin>>m;
		FOR(i,0,m){
			FOR(j,0,m){
				char aux;
				cin>>aux;
				h[i][j]=aux;
			}
		}
		cout<<maxHouse(m)<<endl;
	}
	return 0;
}
