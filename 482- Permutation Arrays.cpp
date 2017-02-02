#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<=_i; i++)
int main() {
	int n,in,in2;
	char k;
	cin>>n;
	while(n--){
		queue<int> q;
		cin.ignore();
		cin>>in;
		FOR(i,1,in){
			cin>>in2;
			if(in2>in){
				in=in2-i;
			}
		}
		//q.push(in);
	}
	return 0;
}
