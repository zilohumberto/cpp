#include <iostream>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i;i++)
char tic[4][4];
int build(int a){

	return 0;
}
int main() {
	int n=0;
	bool victor=true;
	cin>>n;
	int x,o,p;
	while(victor){
		x=o=p=0;
		if((n*4)-1 > 0){
			int k=0;
			while(k++<3){
				cin>>tic[k][0]>>tic[k][1]>>tic[k][2];
			}
			int n=0;
			while(n++<3){
				if(tic[k][0]=='X'){
					x++;
				}else
				if(tic[k][0]=='O'){
					o++;
				}
			}
			string out="";
			if(o<x){
				out="yes";
			}else if(x==o+1){
				out="no";
			}else{
				out="yes";
			}
			cout<<out<<endl;
		}else{
			victor=false;
		}
		n--;
	}
	return 0;
}
