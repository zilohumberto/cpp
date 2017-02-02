#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int c,n,t,m;
struct nodos{
	int time;
	bool lado;
	nodos(int t, bool l){
			time = t;
			lado = l;
	}
};
int main() {
	int i;
	string lado;
	cin>>c;
	while(c--){
		cin>>n>>t>>m;
		queue<nodos> llegadas;
		while(m--){
			cin>>i>>lado;
			nodos n(i,(lado=="left") ? true : false);
			llegadas.push(n);
		}
		int cant=0,time=0;
		bool lado=true;
		while(!llegadas.empty()){
			if(time>=llegadas.front().time && lado==llegadas.front().lado){
				while(cant<n && time>=llegadas.front().time && lado==llegadas.front().lado){
						cant++;
						llegadas.pop();
				}
				time+=t;
				lado=!lado;
				while(cant-->0){
					cout<<time<<endl;
				}
				cant=0;
			}else{
				if(time>=llegadas.front().time){
					lado=!lado;
				}
				time+=t;
			}
		}
		if(c)
			cout<<endl;
	}
	return 0;
}
/*
1
3 5 7
0 left
1 left
2 left
3 left
5 left
5 right
11 right

5
15
15
15
25






1
2 10 3
0 left
0 left
5 r
*/
