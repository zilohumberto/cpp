//============================================================================
// Name        : map.cpp
// Author      : UDONE
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

//metodos
//begin nodo inicio
//end   nodo final
//rbegin nodo inicio de atras para alante
//rend   no final de atras para alante
//empty  vacio
//size	 tamaño
//max_seze definir tamoño maximo
//at ¿?
//swap intercambian a.(b)
//insert insertar
//erase
//emplece
//count  contar
//find   buscar
//key_comp buscar por key

void ejemplo01(map<int,string> mapa){
//example
//lower_bound
//upper_bound
//erase
	 map<int, string>::iterator itlow,itup;
	itlow=mapa.lower_bound(111);  // itlow points to b
	itup=mapa.upper_bound(311);   // itup points to e (not d!)
	mapa.erase(itlow,itup);
	map<int,string> :: iterator it;
		for(it=mapa.begin();it!=mapa.end();it++){
			cout<<(*it).first <<"-"<<(*it).second<<"/";
		}
		cout<<endl;
}

void ejemplo02(map<int, string> mapa){
//ejemplo de key_comp
	map<int,string>::key_compare mycomp = mapa.key_comp();
	int tope = mapa.rbegin()->first;
	map<int,string>::iterator it = mapa.begin();

	do{
		cout << it->second << " - ";
	}while(mycomp((*it++).first,tope));
	cout<<endl;

}
int main() {
	map<int, string> letras;
	letras[011] = "A";
	letras[111] = "B";
	letras[211] = "C";
	letras[313] = "eD";
	letras[311] = "D";
	letras[312] = "D";
	ejemplo01(letras);
	ejemplo02(letras);
	map<int,string> :: iterator it;
	for(it=letras.begin();it!=letras.end();it++){
		cout<<(*it).first <<"-"<<(*it).second<<"/";
	}
	cout<<endl;
	return 0;
}
