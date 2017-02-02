#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int N,M,p;
	cin>>N>>M;
	p=(N*M);
	if(p%2!=0){
		p--;
	}
	p/=2;
	printf("%d\n",p);
	return 0;
}
