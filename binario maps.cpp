#include <iostream>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
map<int, pair<int,int> > arbol;
class bin{
	public :
		int i;
		bin *izq;
		bin *der;
		bin(int a){
			i=a;
			izq=NULL;
			der=NULL;
		}
		void insertar(bin * & aux,int a){
			if(aux->i<a){
				if(aux->izq != NULL){
					bin *ton;
					aux->izq=ton;
					aux->izq->i=a;
				}else{
					insertar(aux->izq,a);
				}
			}else{
				if(aux->der != NULL){
					bin *ton;
					aux->der=ton;
					aux->der->i=a;
				}else{
					insertar(aux->der,a);
				}
			}
		}
};
void insertar(bin * & raiz, int a){
	if(raiz==NULL){
		bin *b;
		raiz = b;
		raiz->i=a;
	}else{
		insertar(raiz,a);
	}
}
int main() {
	int N;
	cin>>N;
	int nodos[1000];
	FOR(i,0,N){
		cin>>nodos[i];
	}
	bin *raiz;
	FOR(i,0,N){
		insertar(raiz,nodos[i]);
	}
	//cout<<raiz->izq<<endl;
	return 0;
}
