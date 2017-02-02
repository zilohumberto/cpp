#include <iostream>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)

int main() {
	int N,ia,ib,aux,res;
	string a,b;
	cin>>N;
	cin>>a>>b;
	res=0;
	FOR(i,0,N){
		ia=a[i]-'0';
		ib=b[i]-'0';
		if(ia<ib){
			swap(ia,ib);
		}
		res+=min(ia-ib,(9-ia)+(ib+1));
	}
	cout<<res<<endl;
	return 0;
}
