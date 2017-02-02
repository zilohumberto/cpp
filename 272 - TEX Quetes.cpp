#include <iostream>
using namespace std;
int main() {
	string l;
	bool flag=true;
	string linea;
	while(cin>>l){
		linea = "";
		for(int k=0; k<l.length();k++){
			if(l[k]=='"'){
				(flag)? linea +="``": linea +="''";
				flag=!flag;
			}else{
				linea +=l[k];
			}
		}
		cout<<linea<<endl;
	}
	return 0;
}
