#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i;i++)
int main() {
	char s[1000000];
	unsigned int l;
	while(gets(s)){
		l=strlen(s);
		unsigned int p=0;
		unsigned int k=0;
		FOR(i,0,l){
			if(s[i]==' ' || i==l-1){
				p=i;
				if(i!=l-1){
					p--;
				}
				while(k < p){
					char aux = s[k];
					s[k] = s[p];
					s[p] = aux;
					k++;
					p--;
				}
				k=i+1;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
