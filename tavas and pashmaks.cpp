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
double N,s,r,maxi;
vector<int> kin;
int main() {
	cin>>N;
	maxi=0;
	int aa=0;
	FOR(i,0,N){
		cin>>s>>r;
		aa=maxi;
		maxi=max(maxi,(s+r));
		if(maxi!=aa){
			kin.clear();
			kin.push_back(i+1);
		}else if(r+s==maxi){
			kin.push_back(i+1);
		}
	}
	FOR(i,0,kin.size()){
			printf("%d",kin[i]);
			if(i+1<N)
				printf(" ");
	}
	printf("\n");
	return 0;
}






