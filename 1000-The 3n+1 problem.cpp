/*Uva 1000- the 3n + 1 problem
 * */
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define N 1000001
static unsigned short dp[N];

unsigned short solve(register unsigned long k){
	if(k< N && dp[k])
		return dp[k];

	if(k%2 == 0){
		if(k < N)
			return dp[k] = 1+solve(k>>1);
		else
			return 1+solve(k>>1);
	}else{
		if(k<N)
			return dp[k] = 2+solve((3*k+1)>>1);
		else
			return 2+solve((3*k+1)>>1);
	}
}

int main() {
	unsigned long i=0,ii,jj,j=0;
	memset(dp,0,sizeof dp);
	dp[1]=1;
	while(cin>>ii>>jj){
		unsigned short out=0;
		i = min(ii,jj);
		j = max(ii,jj);
		for(unsigned int k=i; k<=j;k++){
			out = max(out, solve(k));
		}
		cout<<ii<<" "<<jj<<" "<<out<<endl;
	}
	return 0;
}
