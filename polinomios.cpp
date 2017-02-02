#include <iostream>
#include <list>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
class nodo{
public:
	int constante;
	char letra;
	//float potencia;
	char signo;
	nodo(){
		//constante=potencia=0;
		letra=signo=' ';
		constante=0;
	}
	nodo(char l,char s){
		letra=l;
		constante=1;
		//potencia=p;
		signo=s;
	}
};
list<nodo> expresion;

void simplificar(){

}
void picar(string poli){
	FOR(i,0,poli.size()){
		char aux='+';
		if(poli[i++]=='-') aux='-';
		nodo *nuevo=new nodo(poli[i],aux);
		expresion.push_front(*nuevo);
	}
	simplificar();
}

void mostrar(int s){
	/*FOR(i,0,s){
		cout<<expresion.pop_front()->letra<<endl;
	}*/
}

int main() {

	int n=0; //cantidad de polinomios
	cin>>n;
	while(n-->0){
		int m=0,p=0; //cantidad de noditos
		string polinomio;
		cin>>m;
		while(m-->0){
			p++;
			cin>>polinomio;
			picar(polinomio);
			mostrar(polinomio.size());
		}

	}
	return 0;
}
