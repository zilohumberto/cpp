#include <iostream>
#include <stdio.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i;i++)
int main() {
	int N,c,ans=0,p=0;
	scanf("%d",&N);
	FOR(i,0,N){
		c=0;
		FOR(j,0,3){
			scanf("%d",&p);
			c+=p;
		}
		if(c>1) ans++;
		c=0;
	}
	printf("%d\n",ans);
	return 0;
}
