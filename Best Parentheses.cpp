/*ejercicios 1983 Best Parentheses de COJ
 *Ejemplito de una pila
 * */
#include <iostream>
#include <stack>
using namespace std;
stack<short> st;
int contar(int cont){
	int i=0;
	while(!st.empty())
		if(st.top()==1){
			cont++;
			i++;
			st.pop();
		}else{
			cont--;
			st.pop();
			if(cont<0)
				return cont;
		}
	return cont==0 ? i : -1;
}
int main() {
	int n=0;
	cin>>n;
	short a;

	while(n-->0){
		cin>>a;
		st.push(a);
	}
	cout<<contar(0)%12345678910<<endl;
	return 0;
}
