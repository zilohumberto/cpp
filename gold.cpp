#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int main() {
	int casos,ans,N;
	scanf("%d",&casos);
	ll n,a,b;
	while(casos--){
		ans=0;
		scanf("%d %lld %lld",&N,&a,&b);
		n=pow(2,N);
		if(b<a)
			swap(a,b);
		printf("- %lld -\n",n);
		while(b<n){
			n/=2;
			ans++;
			printf("A %lld\n",n);
		}
		while(a<n){
			n/=2;
			ans++;
			printf("B %lld\n",n);
		}
		printf("---");
		printf("%d\n",ans);
	}
	return 0;
}
