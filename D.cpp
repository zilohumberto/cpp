#include <string>
#include <math.h>
#include <algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<=_i;i++)
#define SIZE 10000
int n,m;


/*#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>

using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
#define SIZE 10000
int n,m;
int c[SIZE][SIZE];
int k[SIZE];
bool v[SIZE];

stack<int> solucion(int yo,int ta){
	stack<int> st;
	queue<int> pos;
	int aux=yo;
	bool tap=false;
	FOR(i,0,n){
		if(v[i]==false){
			aux+=k[i];
			if(aux==ta){
				tap=true;
				pos.push(i);
				break;
			}
			if(aux<ta){
				pos.push(i);
			}else{
				tap=false;
				break;
			}
		}
	}
	if(tap==true){
		while(!pos.empty()){
			v[pos.front()]=false;
			pos.pop();
		}
		return st;
	}
	return st;
}
int main() {
	cin>>n>>m;
	int k[m];
	int c[n];
	int divisor[m];
	FOR(i,0,n){
		k[i]=i+1;
		v[i]=false;
	}
	queue<string> out;
	FOR(i,0,m){
		stack<int> st;
		st=solucion(k[i],n);

		string aux="";
		v[i]=true;
		if(!st.empty())
			out.push(st.size()+"");
		while(!st.empty()){
			aux += st.top()+" ";
		}
		out.push(aux);
	}
	while(!out.empty()){
		cout<<out.front()<<endl;
		out.pop();
	}
	return 0;
}*/
