#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	string line;
	int con=0,cas=1;
	int Z,L,I,M;
	while(cin>>Z>>I>>M>>L, Z!=0 && I!=0 && M!=0 && L!=0){
		con=0;
		int res = (Z*L+I) % M;
		L=res;
		while(res != L || con==0){
			L = (Z*L+I) % M;
			con++;
		}
		printf("Case %d: %d\n",cas++,con);
	}
	return 0;
}
/*
1111 1111 1111 1111
9999 9999 9999 9999
9876 5432 1234 1786
1234 5678 8956 8524
9999 1111 9999 1111
*/
