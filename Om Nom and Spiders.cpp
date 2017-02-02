#include <iostream>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i; i++)
int main() {
	int n,m,k;
	cin>>n>>m>>k;
	char a[n][m];
	FOR(i,0,n){
		FOR(j,0,m){
			cin>>a[i][j];
		}
	}
	FOR(i,0,m){
		int aux=0;
		FOR(j,1,n){
			//hasta aqui llegue yo.
			if(j-i >= 0) aux += (int)(a[i][j-i] == 'R');
			if(j+i  < m) aux += (int)(a[i][j+i] == 'L');
			if(i+i  < n) aux += (int)(a[2*i][j] == 'U');
		}
		cout<<aux<<" ";
	}
	cout<<endl;
	return 0;
}
