#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int main() {
	int N=0,ans=0;
	char s[2];
	int a=1;
	cin>>N;
	cin>>s;
	if(s[0]=='0'){
		a=1;
	}
	ans=1;
	FOR(i,1,N){
		cin>>s;
		if(s[0]=='0' && a==1){
				ans++;
				a=0;
		}else if(s[0]=='1' && a==0){
			ans++;
			a=1;
		}
	}
	//printf("%d\n",ans);
	return 0;
}
