//Evaluar expresiones usando las siguientes estructuras
//Pilas
#include <iostream>
#include <stack>
using namespace std;
bool operando(char ex){
	if(ex=='+') return true;
	if(ex=='-') return true;
	if(ex=='/') return true;
	if(ex=='*') return true;
	return false;
}
int operar(int a, char ex, int b){
	if(ex=='+') return a+b;
	if(ex=='-') return a-b;
	if(ex=='/'){
		if(a>0) return b/a; else return 0;
	}
	if(ex=='*') return a*b;
	return 0;
}
int postfija(string expresion){
	stack<int> pos;
	int i=0;
	do{
		if(operando(expresion[i])==0){
			pos.push(expresion[i]-'0');
		}else{
			int a=pos.top();
			pos.pop();
			int b=pos.top();
			pos.pop();
			pos.push(operar(a,expresion[i],b));
		}
	}while(++i<expresion.size());
	return pos.top();
}

int main() {
	cout<<postfija("23+")<<endl; //out 5
	cout<<postfija("54*53+/")<<endl; //out 2.5
	return 0;
}
