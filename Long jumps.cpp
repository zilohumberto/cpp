#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int main() {
	int n,l,x,y;
	int a[100005],xy[2];
	scanf("%d %d %d %d",&n,&l,xy+0,xy+1);
	bool w=false,e=false;
	FOR(i,0,n){
		scanf("%d",a+i);
		if(binary_search(a,a+i,a[i]-xy[0])) w=true;
		if(binary_search(a,a+i,a[i]-xy[1])) e=true;
	}
	if(w && e){
		puts("0");
		return 0;
	}
	int ans=0,ans2[2];
	if(!w){
		FOR(i,0,n){
			if(abs(a[i]-xy[0]) <= a[n-1]){
				w=!w;
				ans2[ans]=abs(a[i]-xy[0]);
				ans++;
				break;
			}
		}
	}
	if(!e){
			FOR(i,0,n){
				if(abs(a[i]-xy[1]) <= a[n-1]){
					e=!e;
					ans2[ans]=abs(a[i]-xy[1]);
					ans++;
					break;
				}
			}
	}
	printf("%d\n",ans);
	FOR(i,0,ans){
		printf("%d ",ans2[i]);
	}
	return 0;
}
