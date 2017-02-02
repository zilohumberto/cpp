//COJ 2930 Assembly I
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i;i++)
int N;
int ori[20005];
int memo[20005][20005];
int memo2[20005][20005];
int D(int i,int valor){
	if(i==N)
		return 0;
	if(memo2[i][valor]!= -1)
		return memo2[i][valor];

	if(ori[i]<valor)
		return memo2[i][valor]=max(1+D(1+i,ori[i]),D(1+i,valor));

	return memo2[i][valor]=D(1+i,valor);
}

int C(int i,int valor){
	if(i==N)
		return 0;
	if(memo[i][valor] != -1)
		return memo[i][valor];

	if(valor<ori[i])
		return memo[i][valor]=max(1+C(1+i,ori[i]),C(1+i,valor));

	return memo[i][valor]=C(1+i,valor);
}
int main(){
	while(cin>>N){
		FOR(i,0,N) cin>>ori[i];
		int dec=0,cre=0;
		memset(memo,-1,sizeof(memo));
		memset(memo2,-1,sizeof(memo2));
		FOR(i,0,N){
			cre=max(cre,C(1+i,ori[i])+1);
			dec=max(dec,D(1+i,ori[i])+1);
		}
		if(cre==dec)
			printf("Caution. I will not intervene.\n");
		else
			printf("Don't worry. I must intervene.\n");

	}
	return 0;
}

/*
6
10 25 20 22 90 91
5
10 10 10 10 10
5
1 20 50 49 48
*/
