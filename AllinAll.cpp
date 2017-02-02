/*Problema All in All de COJ
 * tenemos dos cadenas s y t
 * diga si s es subsecuencia de t
 * ejemplos
 *
 * input
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter

   output

   Yes
   No
   Yes
   No
a a
aa a
ab ba
ba ab
ta ta
pppp ppppp
hola mundohola
 * */

#include <iostream>
#include <string>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
int main() {
	string s,t;
	int aa=0,tp=0,i,j;
	while(cin>> s >> t){
		aa=0;
		if(s == t){
			cout<<"Yes"<<endl;
		}else
		if(s.length() < t.length()){
				tp=0;
				FOR(i,0,s.length()){
					for(j=tp; j<t.length();j++){
						if(s[i] == t[j]){
							aa++;
							t[j]='*';
							break;
						}
					}
					tp=j;
				}
				if(aa==s.length())
							cout<<"Yes"<<endl;
				else
							cout<<"No"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
