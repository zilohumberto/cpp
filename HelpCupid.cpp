#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
#define FORD(i,a,b) for(int i=(a),_i=(b); i<_i;i+=2)
int main(void){
	int N,hc[24]={},aux;
	cin>>N;
	FOR(i,0,N){
		cin>>aux;
		hc[aux+11]++;
	}
	FOR(i,0,24){
		hc[i]= hc[i]&1;
	}
	int A[64], ret=0x3f3f3f3f,m=0;
	FOR(i,0,24)
		if(hc[i])
			A[m++]=i;
	FOR(i,0,m)
		A[i+m]=A[i]+24;
	if(m==0) ret=0;
	int c;
	FOR(i,0,m){
		c=0;
		FORD(j,0,m)
			c+=A[i+j+1]-A[i+j];
		ret=min(ret,c);
	}
	cout<<ret<<endl;
	return 0;
}
/*
6
-3 -10 -5 11 4 4
2
-6 6
8
0 0 0 0 0 0 0 0
*/
