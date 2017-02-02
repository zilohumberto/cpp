//WA
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int main() {
	int n,m;
	int f[10005];
	cin>>n>>m;
	FOR(i,0,m){
		cin>>f[i];
	}
	sort(f,f+m);
	int best = 0x3f3f3f3f;
	if(m-n==0) best=0;
	FOR(i,1,m-n){
		best = min(best, f[i+n-1]-f[i]);
	}
	cout<<best<<endl;
	return 0;
}
