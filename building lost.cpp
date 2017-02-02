#include <stdio.h>
#include <math.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<=_i;i++)
int main(){
	int N,aux,ans=0;
	int casos;
	scanf("%d",&casos);
	while(casos--){
		scanf("%d",&N);
		ans=-1;
		FOR(i,1,N-1){
			scanf("%d",&aux);
			if(aux!=i && ans==-1)
				ans=i;
		}
		if(ans==-1) ans=N;
		printf("%d\n",ans);
	}
	return 0;
}
