//============================================================================
// Name        : Priority_queue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define sum 2+2
int calcular(queue<int> cola, int j){
	int ant=cola.front(),sig,dif=0;
	cola.pop();
	int i=1;
	while(!cola.empty()){
		if(j==i){
			cola.pop();
		}
		if(!cola.empty()){
			sig = cola.front();
			cola.pop();
			dif = max(dif,(sig-ant));
			ant = sig;
		}
		i++;
	}
	return dif;
}

int main() {
		int th,cant=5;
		cout<<sum*4<<endl;
		//cin >> cant;
		queue<int> v;
		v.push(1);
		v.push(2);
		v.push(3);
		v.push(7);
		v.push(8);
		/*for(int i=0;i<cant;i++){
			cin >> th;
			v.push(th);
		}*/
		priority_queue<int, deque<int>, greater<int> > p;
		for(int i=1;i<cant;i++){
			p.push(calcular(v,i));
		}
		p.pop();
		cout << p.top()<< endl;
	return 0;
}
