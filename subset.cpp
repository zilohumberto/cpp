#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i; i++)
#define FORR(i,a,b) for(int i=(a), _i=(b); i>=_i; i--)
#define max 10000000
int N,T,j;
//vector<int> ori;
int memo[45][45];
int ori[45];
int solved(int i, int j){
	if(j==N || i==N || i==j){
		return 0;
	}
	if(memo[i][j]!= -1){
		return memo[i][j];
	}
	int sol=0;
	FOR(k,i+1,N){

	}
	return memo[i][j]=sol;
}
int main(){
	while(cin>>N>>T){
		memset(memo,0,sizeof(memo));
		FOR(i,0,N){
			cin>>ori[i];
		}
		j=solved(0,1);
		printf("%d\n",j);
	}
	return 0;
}
/*
10 0
0 1 2 3 4 5 6 7 8 9
6 0
-1 2 -3 4 -5 6
5 0
-7 -3 -2 5 8
*/
