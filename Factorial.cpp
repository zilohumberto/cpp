//calcula recursivo del factorial de un numero
#include <iostream>
using namespace std;
//se declara unsigned para que tome desde 0 hasta 32bist es decir 4.294967
unsigned int factorial(unsigned int fac){
	if(fac==0){
		return 1;
	}
	return fac*factorial(fac-1);
}
int main() {
	unsigned int fac=0;
	while(cin>>fac){
		cout<<factorial(fac)<<endl;
	}
	return 0;
}
