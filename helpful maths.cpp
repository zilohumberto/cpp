#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b);i<_i; i++)
int main() {
	string in;
	vector<int> carrilero;
	cin>>in;
	FOR(i,0,in.length()){
			carrilero.push_back(in[i]-'0');
			i++;
	}
	sort(carrilero.begin(),carrilero.end());
	FOR(i,0,carrilero.size()-1){
		printf("%d+",carrilero[i]);
	}
	printf("%d\n",carrilero[carrilero.size()-1]);
	return 0;
}
