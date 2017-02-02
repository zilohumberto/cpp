#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
#define pb push_back
typedef pair<int, int> pa;
bool compare(pa const a, pa const b){
	 if(a.first == b.first)
		 return a.second<b.second;
	 return a.first < b.first;
}
int main() {
	int N,a,b;
	vector<pa> test;
	scanf("%d",&N);
	FOR(i,0,N){
		scanf("%d %d",&a,&b);
		test.pb(make_pair(a,b));
	}
	int inf=-100;
	sort(test.begin(),test.end(),compare);
	FOR(i,0,N){
		if(inf<=test[i].second){
			inf=test[i].second;
		}else{
			inf=test[i].first;
		}
	}
	printf("%d\n",inf);
	return 0;
}
/*
3
5 2
3 1
4 2

3
6 1
5 2
4 3
*/
