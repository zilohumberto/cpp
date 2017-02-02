//11185 - Ternary
#include <iostream>
#include <math.h>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i;i++)
int n;
int ter[20];
void build(){
	FOR(i,0,22){
		ter[i] = pow(3,i);
	}
}
int main() {
	int n = 0;
	build();
	bool vic=true;
	while(vic){
		if(vic){
			cin>>n;
			if(n < 0){
				vic = false;
			}
			int i=0;
			i=9;
			if(n==1){
				cout<<"1"<<endl;
			}else if(n==0){
				cout<<"0"<<endl;
			}else{
				if(n>1000000000) n=1000000000;
				if(ter[i] > n){
					for(i=9; ter[i]>n;i--){

					}
				}else{
					for(i=9; ter[i]<n;i++){

					}
					i--;
				}
				int k=0;
				while(n>0 || i>=0){
					k=0;
					while(n-ter[i] >= 0){
						n-=ter[i];
						k++;
					}
					cout<<k;
					i--;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
/*
21202002000210100
2120200200333341
222695
111212010
12002011200
110012012
110100
22020
121221020222
121221020222
111100200201
1
101
10201
1101001
111201101
12002011201
12122021111


 */
