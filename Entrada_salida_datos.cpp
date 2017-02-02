#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
void lectura_A(){
	//lectura de archivos
}

void escritura_A(){
	//escritura en archivos
}

void usos_scanf(){
	//distintos usos o tipos de scanf
	//EOF elemento de cstdio
	//al igual que scanf
	int n;
	while(scanf("%d",&n)!=EOF) {
		cout<<n<<endl;
	}
}
void usuos_cin(){
	//ignore
	//count
	//get
	short i=0;
		if(cin>>i){
			cout<<i<<endl;
		}
		//entrada
		string iii="";
		cin>>iii;
		//salida
		cout<<iii<<endl;

		char ii;
		cin>>ii;
		//salida solo saldra el primer caracter
		cout<<ii<<endl;
}
void getLine(){
	//optiene un string
	string name;
	getline(cin,name);
	//optiene una arreglo de caracteres //perfecto
	const int l=3;
	//si l=3 nome=ho
	char nome[l];
	//se define el limite
	cin.getline (nome,l);

	cout<<name<<"-"<<nome<<endl;
}
void usos_salidas(){
	cout <<"Ejemplo de salida."<<endl;
	//saldran una serie de numeros en la misma linea
	for(int i=1;i<=10;i++)
		cout<<i<<" ";
	cout<<endl;
	//cout
	//printf
}
//scan tiene varias modalidades
int main() {
	usos_salidas();
	getLine();
	return 0;
}
