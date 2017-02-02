Flexible spaces
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int p,w;
vector<int> cortes;
int dif[120];
int main(){
	scanf("%d %d",&p,&w);
	int c;
	cortes.push_back(0);
	FOR(i,0,w){
		scanf("%d",&c);
		cortes.push_back(c);
	}
	cortes.push_back(p);
	fill(dif,dif+120,0);
	FOR(i,0,cortes.size()-1){
		FOR(j,i+1,cortes.size()){
			dif[abs(cortes[i]-cortes[j])]=1;
		}
	}
	int j=0;
	bool b=false;
	FOR(i,0,110){
		if(dif[i]==1){
			j=i;
			printf("%d",i);
			b=true;
			break;
		}
	}
	FOR(i,j+1,110){
		if(dif[i]==1){
			printf(" %d",i);
		}
	}
	if(b)
		puts("");
	return 0;
}
