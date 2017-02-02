#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define mod 1000000007
typedef unsigned long long ll;
ll per[1000000];

ll permutacion(int i){
	if(per[i]!=-1)
			return per[i];
	if(i==1)
		return per[i]=1;

	return per[i]=((i*permutacion(i-1))%mod);

}

int main() {
	int m,n;
	memset(per,-1,sizeof(per));
	//while(scanf("%d %d",&m,&n)!=EOF){
	scanf("%d %d",&m,&n);
		if(n==0)
				puts("1");
		else{
			int mm=m+n;
			ll a =permutacion(mm);
			ll b =permutacion(n);
			ll c =permutacion(m);
			printf("%lld %lld %lld\n",a,b,c);
		}
	//}
	return 0;
}
