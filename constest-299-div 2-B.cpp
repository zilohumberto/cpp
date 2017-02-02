#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <strstream>
#include <sstream>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b);i<_i; i++)
#define pb push_back
#define size 100
int main() {
	int i=0,a=4,p=1000000;
	int N;
	cin>>N;
	if(N==4){
		cout<<1;
		return 0;
	}
	if(N==7){
		cout<<2;
		return 0;
	}
	int ans=2;
	strstream ss;
	ss<< N;
	string s= ss.str();
	int k=s.length()-1;
	cout<<k<<endl;
	while(k>1){
		ans*=2;
		k--;
	}

	cout<<ans<<endl;
	return 0;
}
