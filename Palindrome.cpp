/*
 * Ejemplo practico del uso de las siguientes estructuras
 * arreglo
 * cola y pila
 * dipolo
 * Para dar respuesta si una palabra es palindrome
 * */
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)

bool palindrome_cola(string palabra){
	queue<char> letras1;
	stack<char> letras2;
		int len=palabra.size();
		if(len%2==1) return false;
		FOR(i,0,len){
			(i<len/2)  ?  letras1.push(palabra[i]) : letras2.push(palabra[i]);
		}
		while(!letras1.empty() || !letras2.empty()){
			if(letras1.front()!=letras2.top()){
				return false;
			}
			letras2.pop();
			letras1.pop();
		}
	return true;
}


deque<char> picarCadenaDeque(string p){
	deque<char> aux;
	FOR(i,0,p.size()){
		aux.push_front(p[i]);
	}
	return aux;
}

bool palindrome_deque(deque<char> letras){
	if((letras.size()%2)==1){
			return false;
	}else{
		while(!letras.empty()){
			if(letras.front()!=letras.back()){
				return false;
			}
			letras.pop_back();
			letras.pop_front();
		}
	}
	return true;
}

bool palindrome_vector(string palabra){
	if(palabra.size()%2==1) return false;
	int j,len;
	len=j=palabra.size();
	len/=2;
	j--;
	FOR(i,0,len){
		if(palabra[i]!=palabra[j])
			return false;

		j--;
	}
	return true;
}

int main() {
	string palabra;
	while(cin >> palabra){
		palindrome_vector(palabra) ? cout<<"YES"<<endl : cout<<"NO"<<endl ;
		palindrome_cola(palabra)  ? cout<<"YES"<<endl : cout<<"NO"<<endl ;
		palindrome_deque(picarCadenaDeque(palabra))  ? cout<<"YES"<<endl : cout<<"NO"<<endl ;
	}
	return 0;
}
