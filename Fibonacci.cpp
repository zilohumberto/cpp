//solucion recursiva y por dp a la serie fibonacci
#include <iostream>
#include <string.h>
unsigned long long int dp[10000005];
using namespace std;

unsigned long long int fibonacci2(unsigned long long int fib){

	if(fib<=2){
		return fib=1;
	}else{
		return fibonacci2(fib-1) + fibonacci2(fib-2);
	}
}
unsigned long long int fibonacci(unsigned long long int fib){
	if(dp[fib]!=-1) return dp[fib];
	if(fib<=2)
		return dp[fib]=1;
	return dp[fib]=fibonacci(fib-1)+fibonacci(fib-2);
}
int main() {
	int fib=0;
	memset(dp,-1,sizeof(dp));
	while(cin>>fib){
		cout<<fibonacci(fib)<<endl;
		cout<<fibonacci2(fib)<<endl;
	}
	return 0;
}
