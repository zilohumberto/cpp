281A - Word Capitalization
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int main() {
		string s;
		cin>>s;
		s[0]=toupper(s[0]);
		cout<<s<<endl;
	return 0;
}