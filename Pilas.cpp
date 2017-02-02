#include <iostream>
#include <stack>
using namespace std;
#define SIZE 10
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
stack<int> st;
int num[SIZE] = {2,1,3,4,5,6,7,8,9,10};
//metodos de la pila
//empty si esta vacio
//size  el tamaño
//top	el tope
//push	insertar
//pop	sacar de la pila
//swap
//emplace
int main() {
	FOR(i,0,SIZE)
			st.push(num[i]);
	if(st.empty()!=1){
		cout<<st.size()<<endl;
		cout<<st.top()<<endl;
	}
	return 0;
}
