#include <stdio.h>
#include <string.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
#define max 7489+1
int N;
int memo[max][max];
int costo[5]={1,5,10,25,50};
int main() {
	//while(scanf("%d",&N)!=EOF){
	scanf("%d",&N);
	FOR(i,0,N){
			FOR(j,0,N){
				memo[i][j]=0;
			}
		}
		FOR(i,0,6){
			if(N-costo[i]>=0)
				memo[N-costo[i]][0]=1;
		}
		FOR(j,1,max){
			FOR(i,0,N){
				if(memo[i][j-1]){
					FOR(k,0,5){
						if(i-costo[k]>=0){
								memo[i-costo[k]][j]=1;
						}
					}
				}
			}
		}
		FOR(i,0,N){
			FOR(j,0,N){
				printf("%d ",memo[i][j]);
			}
			printf("\n");
		}
		int ans=0;
		FOR(i,0,N){
			ans+=memo[0][i];
		}
		printf("%d\n",ans);
	//}
	return 0;
}
