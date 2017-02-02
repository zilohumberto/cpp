#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int n;
typedef pair<int, int> pp;

int main(){
	string s;
	getline(cin,s);
	FOR(i,0,s.length()){
		char aux=s[i];
		if(i==0 && s[i]=='0'){
			continue;
		}
		if(9-(s[i]-'0') < s[i]-'0'){
			int t=s[i]-'0';
			if(9-t==0 && i==0){
				cout<<s[i];
			}else{
				cout<<(9-t);
			}
		}else{
			cout<<aux;
		}
	}
	cout<<endl;
	return 0;
}
