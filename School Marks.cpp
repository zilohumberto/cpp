//pendiente contest 301 codeforces
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
int main() {
	int n,k,p,x,y,aux,sum=0;
	vector<int> ks;
	cin>>n>>k>>p>>x>>y;
	FOR(i,0,k){
		cin>>aux;
		sum+=aux;
		ks.push_back(aux);
	}
	if(sum>x){
		cout<<"-1"<<endl;
		return 0;
	}
	FOR(i,0,n-k){
		FOR(j,1,p){
			vector<int> ks2=ks;
			if((sum+j) < x){

			}
		}
	}
	cout<<ks.size()<<endl;
	sort(ks.begin(), ks.end());
	if(ks.size()+1==n){
		FOR(i,0,n){
			cout<<ks[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
