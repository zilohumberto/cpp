/*573- The Snail / Uva*/
#include <iostream>
using namespace std;

int main() {
	//altura del pozo, climb to day,baja to night, fatiga
	double H,U,D,F;
	double pos=0;
	int dias=1;
	bool flag = true;
	bool victor=true;
	while(victor){
		cin>>H>>U>>D>>F;
		if(H==0){
			victor=false;
		}else{
			dias=1;
			flag=true;
			F=F/100*U;
			pos=0;
			while( (pos>=0) && (pos<=H) ){
				if(flag==false){
					U=U-F;
					if(U<0) U=0;
					pos+=U;
				}else{
					pos= (U);
					flag=!flag;
				}
				if(pos<0 || pos>H){
					break;
				}
				pos-=D;
				if(pos<0 || pos>H){
					break;
				}
				++dias;
			}
			if(pos>H){
				cout<<"success on day "<<dias<<endl;
			}else{
				cout<<"failure on day "<<dias<<endl;
			}
		}
	}
	return 0;
}

/*Sample Input
2 2 2 20
8 6 5 30
97 56 3 10
56 3 1 5
85 26 19 10
59 17 13 11
97 73 23 17
0 0 0 0

Sample Output

success on day 3
failure on day 4
failure on day 7
failure on day 68
success on day 20
failure on day 2
 * */
