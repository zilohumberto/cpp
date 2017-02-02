#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b);i<_i; i++)
int main(){
	string hola;
	int sum=0;
	bool o=false,h=false,a=false;
	int l=0;
	getline(cin,hola);
	FOR(i,0,hola.length()){
		if(hola[i]=='h'){
			h=true;
		}
		if(hola[i]=='o'){
			o=true;
		}
		if(hola[i]=='l'){
			l++;
		}
		if(hola[i]=='a'){
			h=true;
		}
	}
	if(a==true && h==true && o==true && l>=2){
		puts("YES");
	}else{
		puts("NO");
	}
		return 0;
}
/*
10
1 1 1 1 1 1 1 1 1 1
9
1 1 1 1 1 1 1 1 1 1
9
1 2 3 4 5 6 8 6 5
 3
 1 2 3
 6
 1 2 3 4 5 6
 2
 1 2
 3
 1 3 3
 3
 2 1 2
 2
 3 3
 */
