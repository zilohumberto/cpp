#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b);i<_i;i++)
int main() {
	int n,c_pagas;
	cin>>n;
	while(n--){
		cin>>c_pagas;
		map<char,int> pagadas;
		char letra;
		int cant;
		FOR(i,0,c_pagas){
			cin>>letra>>cant;
			pagadas[letra]=cant;
		}
		int k;
		cin>>k;
		int acum=0,penny=0;
		cin.ignore();
		FOR(i,0,k){
			char cadena[10000];
			gets(cadena);
			int len=strlen(cadena);
			FOR(i,0,len){
				acum+=pagadas[cadena[i]];
			}
		}
		printf("%.02f$\n",acum/100.0);
	}
	return 0;
}
