#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i; i++)

typedef pair<char, char> und;
vector< stack<und> > cartas;

bool igualRango(und a, und b){
	if(a.first==b.first || a.second==b.second){
		return true;
	}
	return false;
}
void cambio(int i, int k){
	cartas[k].push(cartas[i].top());
	cartas[i].pop();
	if (cartas[i].empty()) cartas.erase(cartas.begin() + i);
}
int main() {
	string in;
	while(cin>>in){
		if(in[0]=='#'){
			break;
		}else{
			cartas.clear();
			stack<und> aux;
			aux.push(und(in[0],in[1]));
			cartas.push_back(aux);
			FOR(i,0,51){
				stack<und> aux;
				cin>>in;
				aux.push(und(in[0],in[1]));
				cartas.push_back(aux);
			}
			//hasta aqui es la entrada
			for (int i = 0; i < cartas.size(); i++) {
				if(i>=3 && igualRango(cartas[i].top(), cartas[i-3].top())){
					cambio(i,i-3);
					i-=4;
				}else if(i>=1 && igualRango(cartas[i].top(), cartas[i-1].top())){
					cambio(i,i-1);
					 i -= 2;
				}
			}
			int p=cartas.size();
			string piles="pile";
			if(cartas.size()>1){
				piles+="s";
			}
			cout<<p<<" "<<piles<<" remaining:";
			FOR(i,0,p){
				cout<<" "<<cartas[i].size();
			}
			cout<<endl;
		}
	}
	return 0;
}
