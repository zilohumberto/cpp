#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b);i<_i; i++)
int main() {
	int N;
	cin>>N;
	string line;
	getchar();
	while(N--){
		getline(cin,line);
		int p=line.length();
		bool a=false,salida=true;
		int aa=0,bb=0;
		stack<bool> orden;
		if(line[0]=='('){
			orden.push(true);
			aa++;
		}else if(line[0]=='['){
			orden.push(false);
			bb++;
		}else if(line[0]==']' || line[0]==')'){
			salida=false;
			p=0;
		}
		FOR(i,1,p){
			if(line[i]=='('){
				orden.push(true);
				aa++;
			}else if(line[i]=='['){
				orden.push(false);
				bb++;
			}else if(line[i]==')'){
				if(orden.empty()){
					salida=false;
					break;
				}else
				if(orden.top()){
					aa--;
					if(aa<0){
						salida=false;
						break;
					}
				}else{
					salida=false;
					break;
				}
				if(!orden.empty()) orden.pop();
			}else if(line[i]==']'){
				if(orden.empty()){
					salida=false;
					break;
				}else
				if(orden.top()==false){
					bb--;
					if(bb<0){
						salida=false;
						break;
					}
				}else{
					salida=false;
					break;
				}
				if(!orden.empty()) orden.pop();
			}
		}
		if(salida==true && aa==0 && bb==0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
