#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int main() {
	long long N,allsum=0;
	long long g[3*100000];
	cin>>N;
	FOR(i,0,N){
		cin>>g[i];
		allsum+=g[i];
	}
	sort(g,g+N);
	long long ans=allsum;
	FOR(i,0,N){
		allsum-=g[i];
		if(i+1==N)
			break;
		ans+=allsum+g[i];
	}
	ans+=allsum;
	cout<<ans<<endl;
	return 0;
}
