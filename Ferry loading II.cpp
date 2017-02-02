#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
#define FORD(i,a,b,n) for(int i=(a),_i=(b);i<_i;i+=n)
int n,m,r;
int main() {
	int N,mic[1445];
	cin>>N;
	while(N--){
		cin>>n>>m>>r;
		FOR(i,0,r){
			cin>>mic[i];
		}
		sort(mic,mic+r);
		m<<=1;
		int tes=0,ans=0,tt=(n+r-1);

		FORD(a,tt%n,r,n){
			ans = max(tes,mic[a]);
			tes = ans + m;
		}
		cout<<(tes-(m>>1))<<" "<<(tt/n)<<endl;
	}
	return 0;
}
/*
1
2 10 10
5
10
20
30
40
50
60
70
80
90

3
3 5 5
1 2 3 4 2
5 5 1
2
3 4 1
5
5 1 2
3 4
*/
