/*Example codeforces
 * tienes s y t. saber si t es subsecuencia de s.
 * */
#include <iostream>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i;i++)
#define cout(s) cout<<s<<endl;
int main() {
	string s,t;
	cin>>s;
	cin>>t;
	if(t.size()>s.size() || t==s){
		cout("NO");
		return 0;
	}
	int ii=0,jj=0;
	FOR(i,0,t.size()){
		FOR(j,jj,s.size()){
			if(t[i]==s[j]){
				ii=i;
				jj=j;
				break;
			}
		}
	}
	if(ii==s.size()-1){
		cout("SI");
	}else cout("NO");
	return 0;
}
