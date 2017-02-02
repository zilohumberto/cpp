#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
   	long long N;
	while(cin>>N, N!=0){
		long long ac = N*N;
		long long ans=ac;
		ans/=N;
		ans = ans * (ac + 1) / 2;
		cout<<ans<<endl;
	}
	return 0;
}
