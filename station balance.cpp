#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
#define abs2(a,b) (a-b<0)? (a-b)*-1 : a-b;
typedef pair<int, int> tu;
bool compare(tu  const a,tu const b ){
	return a.second<b.second;
}

struct st{
		int cm1,cm2;
		int pos1, pos2;
		st(){
			cm1=0;
			cm2=0;
			pos1=0;
			pos2=0;
		}
		void cam1(int p, int c){
			cm1=c;
			pos1=p;
		}
		void cam2(int p, int c){
			cm2=c;
			pos2=p;
		}
		void swaps(){
			if(pos2<pos1){
				swap(pos1,pos2);
				swap(cm1,cm2);
			}
		}
};
bool comparar(st  const a,st const b ){
	return a.pos1<b.pos1;
}
int main() {
	int a,b,sta,caso=1,sum,aux;
	double ave,im;
	vector<tu> masas;
	while(cin>>a>>b){
		st cham[30];
		sum=0;
		masas.clear();
		FOR(i,0,b){
			cin>>aux;
			sum+=aux;
			masas.push_back(make_pair(i,aux));
		}
		ave=(double)sum/a;
		int t=0,h=2*a;
		FOR(c,b,h){
			masas.push_back(make_pair(c+1,0));
		}
		h--;
		sort(masas.begin(),masas.end(),compare);
		FOR(i,0,a){
			cham[i].cam1(masas[t].first,masas[t].second);
			cham[i].cam2(masas[h].first,masas[h].second);
			cham[i].swaps();
			t++;
			h--;
		}
		sort(cham,cham+a,comparar);
		printf("Set #%d\n",caso++);
		int cham1,cham2;
		im=0;
		FOR(i,0,a){
			cham1=cham[i].cm1;
			cham2=cham[i].cm2;
			if(cham2!=0 && cham1!=0)
				cout<<" "<<i<<": "<<cham1<<" "<<cham2<<endl;
			else if(cham1!=0)
					cout<<" "<<i<<": "<<cham1<<endl;
			else
				cout<<" "<<i<<":"<<endl;
			im+=abs2((cham1+cham2),ave);
		}
		printf("IMBALANCE = %.05f\n",im);
		cout<<endl;
	}
	return 0;
}
