/* Amigos Virtuales
 * Aplicacion con
 * matrices estilo grafo y adyacencias
 * map para los nombres
Sample input
1
3
Fred Barney
Barney Betty
Betty Wilma

Sample output
2
3
4
 *
 * */
#include <iostream>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
#define SIZE 10000
int amistades[SIZE][SIZE];
bool visitados[SIZE];
int bfs(int x, int h, int cantA){
	FOR(i,0,h){
		if(x!=i && amistades[x][i]==1){
			cantA++;
		}
	}
	return cantA+1;
}
void insertar(int a, int b, int h){
	FOR(i,0,h){
		if( (i!=b) && (amistades[a][i]==1 || amistades[i][a]==1) && (amistades[i][b]==0 || amistades[i][b]==0)  ){
			amistades[i][b]=amistades[i][b]=1;
			insertar(i,a,h);
		}
	}
	FOR(i,0,h){
		if( (i!=a) && (amistades[b][i]==1 || amistades[i][b]==1) && (amistades[i][a]==0 || amistades[i][a]==0)  ){
			amistades[i][a]=amistades[i][a]=1;
			insertar(i,b,h);
		}
	}
}
int main() {
	int n=0,m=0;
	cin>>n;
	while(n-->0){
		m=0;
		map<string, int> nombres;
		cin>>m;
		string a,b;
		int h=0;
		FOR(i,0,m){
			cin>>a>>b;
			map<string,int>::iterator it;
			bool an=false,na=false;
			for(it=nombres.begin();it!=nombres.end();++it){
				if(it->first==a){
					an=true;
				}else
				if(it->first==b){
					na=true;
				}
			}
			if(an!=true) nombres[a]=h++;
			if(na!=true) nombres[b]=h++;

			amistades[nombres[a]][nombres[b]]=amistades[nombres[b]][nombres[a]]=1;
			insertar(nombres[a],nombres[b],h);
			cout<<bfs(nombres[a],h,0)<<endl;
		}
	}
	return 0;
}
