43A - Footbal
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)


int main() {
	int tc;
	string at;
	map<string,int> mp;
	cin>>tc;
	while(tc--){
		cin>>at;
		mp[at]++;
	}
	string res;
	int goal=0;
	map<string,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		if((*it).second>goal){
			goal=(*it).second;
			res=(*it).first;
		}
	}
	cout<<res<<endl;
	return 0;
}