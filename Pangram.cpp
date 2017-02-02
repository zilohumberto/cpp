#include <iostream>
#include <set>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)

int main() {
	set<char> letras;
	int n=0;
	cin>>n;
	char ni;
	FOR(i,0,n){
		cin>>ni;
		letras.insert(toupper(ni));
	}
	if(letras.size()==26){
		cout<<"YES";
		return 0;
	}else cout<<"NO";
	return 0;
}
