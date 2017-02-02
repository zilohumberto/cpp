#include <iostream>
#include <list>
using namespace std;
#define max_l 10
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
#define cout(a) cout<<a<<" ";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front

list<int> lista;
int a[max_l]={2,1,3,4,5,6,7,8,9,10};
//tamaño de la lista
int size(list<int> l){
	return l.size();
}

void llenar_lista(){
	FOR(i,0,max_l){
		//equivalente al definirlo como
		//lista.push_back(a);
		lista.pb(a[i]);
	}
}
void mostrar(list<int> l){
	FOR(i,0,l.size()){
		cout(a[i]);
	}
	cout<<endl;
}
//iterator example
void iterar(list<int> &lista){
	list<int>::iterator pos;
	pos = lista.begin();
	while(pos != lista.end()){
		cout << *pos<<endl;
		pos++;
	}
}
//iterator reverse
void iterar_r(list<int> &lista){
	list<int>::reverse_iterator pos;
	pos = lista.rbegin();
	while(pos != lista.rend()){
		cout << *pos<<endl;
		pos++;
	}
}
//mezclar dos lista
void mezclar(){
	list <string> staff1;
	 staff1.push_back("Anne");
	 staff1.push_back("Fred");
	 staff1.push_back("Jim");
	 staff1.push_back("Susan");
	 list <string> staff2;
	 staff2.push_back("Barry");
	 staff2.push_back("Charles");
	 staff2.push_back("George");
	 staff2.push_back("Ted");
	 staff2.merge( staff1 );
	 staff2.pb("AAAA");
	 //aqui el sort si funciona
	 staff2.sort();
	 list<string>::iterator pos;
	 	pos = staff2.begin();
	 	while(pos != staff2.end()){
	 		cout << *pos<<" ";
	 		pos++;
	 	}
	 	cout<<endl;
	 staff2.reverse();
	 list<string>::iterator pos2;
	 	 pos2 = staff2.begin();
	 	 while(pos2 != staff2.end()){
	 		 		cout << *pos2<<" ";
	 		 		pos2++;
	 	}
	 	 cout<<endl;
}
//buscar ejemplos
void iterator_find(list<int> &lista){

}
//metodos que no funcionan con enteros o duobles
//reverse
//short

//falta implementar una lista manualmente
//http://www.c.conclase.net/edd/?cap=001
//http://listaencpasoapaso.blogspot.com/
int main() {
	llenar_lista();
	cout <<"La lista tiene : "<< size(lista)<<endl;
	mostrar(lista);
	lista.popb();
	mostrar(lista);
	//mostrar(lista);
	//iterar(lista);
	mezclar();
	return 0;
}
