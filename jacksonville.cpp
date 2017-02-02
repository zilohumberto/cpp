#include <iostream>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int main() {
	int k,n;
	int ns[22];
	int ks[260];
	FOR(i,0,256){
		ks[i]=i+1;
	}
	while(cin>>k>>n){
		if(k==0 && n==0) break;
		FOR(i,0,n){
			cin>>ns[i];
		}
		int ans=0;
		FOR(i,0,k){
			FOR(j,0,n){
				if(ks[i]%ns[j]==0){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
