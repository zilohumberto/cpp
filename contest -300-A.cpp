#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i; i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
	string line;
	getline(cin,line);
	int l = line.length();
	map<char,int> code;
	string c="CODEFORCES";
	FOR(i,0,c.length()){
		code[c[i]] = i;
	}
	int k=0;
	int b=0;
	string sol[1005];
	string aux="";
	FOR(i,0,l){
		if(code[line[i]]==k || line[i]=='C' || line[i]=='O' || line[i]=='E'){
			k++;
			aux+=line[i];
		}else{
			if(aux != ""){
				if(k<5){
					k = code[aux[0]];
					if(k==5){
						k=1;
					}
				}
				if(k<7){
					k = code[aux[0]];
					if(k==7){
						k=0;
					}
				}

				if(k<8){
					k = code[aux[0]];
					if(k==8){
						k=3;
					}
				}
				k = code[aux[0]];
				sol[b++]=aux;
				aux="";
			}
		}
	}
	sol[b++]=aux;
	FOR(i,0,b){
		cout<<sol[i]<<endl;
	}
	//cout<<b<<endl;
	/*if(k>=9 && b<=2){
		cout<<"YES"<<endl;
	}else
		cout<<"NO"<<endl;
	*/return 0;
}
/*
CODESDFDSORCES
CODEWAITFORITFORCES
BOTTOMCODER
*/
