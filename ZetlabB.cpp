#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i; i++)
using namespace std;
char plat[105];
int greddy(int i, int k){
	if(plat[i+k]=='*'){
		return 1+greddy(i+k,k);
	}
	return 0;
}
int main() {
	int n;
	cin>>n;
	FOR(i,0,n){
		cin>>plat[i];
	}
	int victor=-1;
	FOR(i,0,n){
		if(plat[i]=='*'){
			FOR(j,i+1,n){
				if(plat[j]=='*'){
					victor = greddy(j,j-i);
					if(victor>=3){
						cout<<"yes"<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<"no"<<endl;
	return 0;
}
