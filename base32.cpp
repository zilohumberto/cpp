#include <iostream>
#include <bitset>
#include <map>
#include <stdio.h>
#include <bitset>
#include <string>
#include <limits>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i+=5)
int main() {
	map<int,char> chuy;
	chuy[0]='!';
	chuy[1]='@';
	chuy[2]='#';
	chuy[3]='$';
	chuy[4]='%';
	chuy[5]='&';
	char a='a';
	for(int i=0;i<26;i++){
		chuy[i+6]=a+i;
	}
	int t;
	string acum="";
	while(scanf("%d",&t) != EOF){
		acum+= bitset<8>(t).to_string();
	}
	int pows[5]={16,8,4,2,1};
	string out,at;
	out=at="";
	int u,ks;
	for(int i=0;i<acum.size();i+=5){
		ks=0,u=0;
		at = acum.substr(0,5);
		while(u<5){
			if(at[u]=='1')
				ks+=pows[u];
				u++;
			}
		out+=chuy[ks];
		if(out.size()>=80){
			printf("%s\n",out.c_str());
			out="";
		}
		acum=acum.substr(5,acum.size());
		i=0;
	}
	u=0,ks=0;
	while(u<=acum.size()){
		if(acum[u]=='1'){
			ks+=pows[u];
		}
		u++;
	}
	out+=chuy[ks];
	printf("%s\n",out.c_str());
	return 0;
}
/*
219
232
58
99
46

11011 01111 10100 00011 10100 11000 11001 01110
  v    j      o    $      o     s    t      i


-------------------------------------------------
132
101
58

10000 10001 10010 10011 1010
  k     l     m    n     o

255
255
255
255
255

11111 11111 11111 11111 11111 11111 11111 11111
  z     z    z      z     z      z     z     z

255
255
255
255
1

11111 11111 11111 11111 11111 11000 01000
  z     z     z     z     z    	s     @

*/
