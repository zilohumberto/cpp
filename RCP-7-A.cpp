#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
typedef pair<int, int> pp;

int main(){
	int tc;
	string dic,cad,animal,sonido,aux;
	vector<pair<string,bool> > v;
	scanf("%d",&tc);
	getchar();
	while(tc--){
		getline(cin,dic);
		stringstream s;
		s << dic;
		while(s>>aux){
			v.push_back(pair<string,bool>(aux,false));
		}
		while(getline(cin,cad)){
		 if(cad=="what does the fox say?") break;
		 stringstream s;
		 s << cad;
		 s >> animal;
		 s >> animal;
		 s >> sonido;
		 bool enc=false;
		 for(int i=0;i<(int)v.size();++i){
			 if(v[i].first==sonido){
				 v[i].second=true;
			 }
		 }
		}
		int cont=0;
		for(int i=0;i<(int)v.size();++i){
			if(v[i].second==false && cont==0){
				cont=1;
				cout << v[i].first;
			}else{
				if(v[i].second==false){
								cout<<" " << v[i].first;
					}
				}
		}
		cout << endl;
		v.clear();
	}
	return 0;
}
