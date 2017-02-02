/*
 * 3

2
+
3

2
*
3

1
+
0
 */

#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int rango(char k){
	if(k=='+' || k=='-')
		return 0;
	if(k=='*' || k=='/')
		return 1;
	if(k=='(')
		return 2;
	if(k==')') return 3;
	return -1;
}

int main() {
	int N;
	cin>>N;
	cin.ignore();
	cin.ignore();
	int c=0;
	while(N--){
		string token;
		stack<char> op;
		c++;
		if(c>1){
			printf("\n");
		}
		while(true){
			getline(cin, token);
			if (token.length() == 0 || !cin)
						break;
			if(token[0]>='0' && token[0]<='9'){
				printf("%c",token[0]);
			}else{
				int r=rango(token[0]);
				switch(r){
					case 0:{
						while(!op.empty()){
							int rr=rango(op.top());
							if(rr==0 || rr==1){
								printf("%c",op.top());
								op.pop();
							}else{
								break;
							}
						}
						op.push(token[0]);
						break;}
					case 1:{
						if(!op.empty()){
							int rr=rango(op.top());
							if(rr==1){
								printf("%c",op.top());
								op.pop();
							}
						}
						op.push(token[0]);
						break;}
					case 2:{
						op.push(token[0]);
						break;}
					case 3:{
						while(!op.empty() && op.top()!='('){
							printf("%c",op.top());
							op.pop();
						}
						op.pop();
						break;}
				}
			}
		}
		while(!op.empty()){
			printf("%c",op.top());
			op.pop();
		}
			printf("\n");
	}
	return 0;
}



