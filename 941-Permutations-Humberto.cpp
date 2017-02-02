#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
long long fa[25];
long long fac(int i,int f){
	if(f==1){
		return 1;
	}
	return fa[i]=f*fac(i-1,f-1);
}
int main() {
	int N;
	long long Nth;
	fac(20,20);
	cin>>N;
	while(N--){
		string in;
		cin>>in; //¿ como hago scanf con un string?
		scanf("%lld", &Nth);
		int l= in.size();
		long long per= fa[l];
		int my=l-1;
		FOR(i,0,3){

		}
		printf("\n");
	}
	return 0;
}
