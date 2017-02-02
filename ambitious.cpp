#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int N;
int jo[1005][1005];
/*int memo[1005][1005];
int solved(int i, int j){
	if(i==N || j==N)
		return 0;
	if(memo[i][j]!=-1)
			return memo[i][j];
	if((j+1==N && i+2==N) || (j+2==N && i+1==N))
			return memo[i][j]=jo[i][j];
	return memo[i][j]=jo[i][j]+max(solved(i+1,j),solved(i,j+1));
}*/
int main(){
	while(scanf("%d",&N), N!=0){
		FOR(i,0,N)
			FOR(j,0,N){
				//memo[i][j]=-1;
				scanf("%d",&jo[i][j]);
			}
		//int ans=max(solved(0,1),solved(1,0));
		//printf("%d\n",jo[0][0]+ans+jo[N-1][N-1]);
		FOR(j,2,N) jo[0][j]+=jo[0][j-1];
		FOR(i,2,N) jo[i][0]+=jo[i-1][0];
		FOR(i,1,N){
			FOR(j,1,N){
				jo[i][j]+=max(jo[i-1][j],jo[i][j-1]);
			}
		}
		printf("%d\n",jo[0][0]+jo[N-1][N-1]);
	}
	return 0;
}
