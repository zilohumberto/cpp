#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i>=_i;i-=2)
int N;
int main() {
	cin>>N;
		if(N==1){
			printf("%d\n",1);
			puts("1");
			return 0;
		}
		if(N==2){
			puts("1");
			puts("1");
			return 0;
		}
		if(N==3){
			puts("2");
			puts("1 3");
			return 0;
		}
		if(N==4){
			puts("4");
			puts("3 1 4 2");
			return 0;
		}
		printf("%d\n",N);
		if(N%2==1){
			FOR(i,N,1){
				printf("%d ",i);
			}
			FOR(i,N-1,2){
				printf("%d ",i);
			}
		}else{
			FOR(i,N-1,1){
				printf("%d ",i);
			}
			FOR(i,N,2){
				printf("%d ",i);
			}
		}
		cout<<endl;
	return 0;
}
