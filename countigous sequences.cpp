#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
	int N,a,b;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&a,&b);
			ll ans=0;
			if(a<b){
				ans=(ll)a*a;
				if(a>0){
					int t=0,e=0;
					t=b/2a;
					e=b/2;
					if(b%2==1)
						e++;
					ans-=(ll)(t*t);
					ans-=(ll)(e*e);
				}
			}else{
				ans=(ll)a*a;
				if(b>0){
					int t=0,e=0;
					t=b/2a;
					e=b/2;
					if(b%2==1)
						e++;
					ans-=(ll)(t*t);
					ans-=(ll)(e*e);
				}
			}
			printf("%lld\n",ans);
	}
	return 0;
}
/*
6
5 3
1 0
0 1
3 2
1 1
0 2
 */
