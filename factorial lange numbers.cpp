#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	long long int N;
	while(cin>>N, (N!=-1)){
		int j=2;
		while(N>2){
			if(N%j==0){
				printf("%d\n",j);
				N/=j;
			}else{
				j=j+2;
				/*if(j>9){
					break;
				}*/
			}
		}
		if(N>2)
			printf("%lld",N);
		printf("\n");
	}
	return 0;
}
/*
 90
 1234567891
 18991325453139
 12745267386521023
 -1
 */
