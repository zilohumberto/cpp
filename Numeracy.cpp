#include <iostream>
using namespace std;
typedef long long LL;
int main() {
	int n=0;
	cin>>n;
	while(n-->0){
		LL a,b,c,d;
		char op,ig;
		cin>>a;
		cin>>op;
		cin>>b;
		cin>>ig;
		cin>>d;
		if(op=='+'){
			c = a+b;
		}
		if(op=='-'){
			c = a-b;
		}
		if(op=='*'){
			c = a*b;
		}
		if(op=='/'){
			if(b>0){
				c = a/b;
			}else
				c = 0;
		}

		if(c==d && ig=='='){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
