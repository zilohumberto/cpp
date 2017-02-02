#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
	int a;
	int lim=9;
	bool flag=false;
	while(cin>>a){
			lim--;
			if(a != 0){
				if(flag==0){//si es primera vez que hay un a != 0
					if(a<0) cout<<"-";//si a es negativo escribo sin espacio un -
				}else{
					(a<0) ? cout<<" - " : cout<<" + "; //sino es primera vez escribo el signo segun a
				}
				a = abs(a);//ya a se le tomo el signo, lo transformo a abs.
				if(lim==0){
						cout<<a;//si estoy en la ultima iteracion escribo solo el termino ind
				}else if(lim==1){
					(a==1) ? cout<<"x" : cout<<a<<"x";//si es el penultimo
				}else{
					(a==1) ? cout<<"x^"<<lim : cout<<a<<"x^"<<lim;//si es el penultimo
				}
				flag=true;
			}
			if(lim==0){
				lim=9;
				if(flag!=true)
					cout<<"0"<<endl;
				else{
					cout<<endl;
					flag=false;
				}
			}
	}
	return 0;
}
/*
 * 0 0 0 0 0 0 0 0 0
0
0 0 0 0 0 0 0 0 -1
-1
-1 0 0 0 0 0 0 0 0
-x^8
0 -1 0 0 0 0 0 0 0
-x^7
0 0 -1 0 0 0 0 0 0
-x^6
0 0 0 -1 0 0 0 0 0
-x^5
0 0 0 0 0 -1 0 0 0
-x^3
0 0 0 0 -1 0 0 0 0
-x^4
0 0 0 0 0 0 -1 0 0
-x^2
0 0 0 0 0 0 0 -1 0
-x
1 0 0 0 0 0 0 0 0
x^8
100 0 0 0 0 0 0 0 0
100x^8
100 0 0 0 0 0 0 0 100
100x^8 + 100
-1 0 0 0 0 0 0 0 1
-x^8 + 1
-1 -1 2 3 4 5 0 0 0
-x^8 - x^7 + 2x^6 + 3x^5 + 4x^4 + 5x^3
 * */
