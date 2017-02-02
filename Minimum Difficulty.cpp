/*Ejemplo del uso de queue y priorityQueue
 *Ejercicio 496a codeforces.com
 *
 Sample test(s)
input
3
1 4 6
output
5
input
5
1 2 3 4 5
output
2
input
5
1 2 3 7 8
output
4
 * */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
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
		int th,cant;
		cin >> cant;
		queue<int> v;
		for(int i=0;i<cant;i++){
			cin >> th;
			v.push(th);
		}
		priority_queue<int, deque<int>, greater<int> > p;
		for(int i=1;i<cant;i++){
			p.push(calcular(v,i));
		}
		p.pop();
		cout << p.top()<< endl;
	return 0;
}
