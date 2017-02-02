/*Ejercicio de coj
 *Segun la pagina WA.
 *Pero sirve de practica.
 *
 *dice que dada una password
 *se considera a ella segura si no contiene las letras B,R,O,K,E, and N
 *No se porque da error, cualquier sugerencia gracias.
 * */
#include <iostream>
#include <set>
using namespace std;

void revisar(string line){
	set<char> lt;
	for(int i=0;i<line.size();i++){
		if((line[i]=='B') || (line[i]=='R') || (line[i]=='O') || (line[i]=='K') || (line[i]=='E') || (line[i]=='N')){
			lt.insert(line[i]);
		}
	}
	string out;
	(lt.size()==6) ? out="No Secure" : out="Secure";
	cout<<out<<endl;
	return;
}
int main() {
	int n=0;
	cin>>n;
	while(n-->0){
		string line;
		cin>>line;
		revisar(line);
	}
	return 0;
}
