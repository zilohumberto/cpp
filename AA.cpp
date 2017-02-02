#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int n;
	char a;
	int ii,jj;
	int resultado;
	cin>>n;
	while(n--){
		cin>>a>>ii>>jj;
		if(a=='K'){
			 resultado=1;
				 if(ii%2==0){
					 resultado*=(ii)/2;
				 }else{
					 resultado*=(ii+1)/2;
				 }
				 if(jj%2==0){
					   resultado*=(jj)/2;
				  }else{
					   resultado*=(jj+1)/2;
				  }
				  cout<<resultado<<endl;
		}
		if(a=='r' || a=='Q'){
			cout<<min(ii,jj)<<endl;
		}
		if(a=='k')
				cout<<((ii*jj+1)/2)<<endl;
	}
	return 0;
}
