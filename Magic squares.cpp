#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i; i++)
vector<int> ent;
int numM,U,cant,l;
char solved(){
	int mi=0,p,sol=0;
	int ll=(l%2==0) ? l/2 : ((l-1)/2);
	FOR(i,0,ll){
		mi = ent[i];
		FOR(j,i,l){
			p=1;
			//int lle=mi;
			int lle=0;
			int k = j;
			cout<<"---"<<endl;
			cout<<mi<<endl;
			while(p<=U && k<l){
				lle+=ent[k];
				p++;
				k++;
			}
			cout<<lle<<endl;
			if(lle==numM)	sol++;
		}
	}
	cout<<sol<<endl;
	return (sol>=4) ? 'Y' : 'N';
}
int main() {
	string line;
	stringstream s;
	while(getline(cin,line)){
		s << line;
		int a;
		cant=0;
		while(s>>a){
			ent.push_back(a);
			cant+=a;
		}
		l = ent.size();
		U = sqrt(ent.size());
		numM = cant/U;
		char k = 'N';
		if(U==2 || U==3 || U==4){
			k = solved();
		}
		printf("%c\n",k);
		//ent.clear();
	}
	return 0;
}
/*
1 2 3 4 5 6 7 8 9
1 1 1 1
1 14 4 14 11 7 6 9 8 13 10 2 1 3 5 15
4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 8
1 2 3 4
1 1 -1 -1
-1 -1 -1 -1
1 1 1

*/
