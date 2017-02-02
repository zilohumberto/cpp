#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
long long memo[64][10];
int main(){
	int N,a,b;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&a,&b);
		long long ans=0;
		FOR(i,0,11){
			memo[0][i]=1;
		}
		long long acum=10;
		FOR(i,1,b){
			memo[i][0]=acum;
			FOR(j,1,10){
				memo[i][j]=memo[i][j-1]-memo[i-1][j-1];
				acum+=memo[i][j];
			}
		}
		printf("%d %lld\n",a,acum);
	}
	return 0;
}
