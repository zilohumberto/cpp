#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
#define FORR(i,a) for(int i=(a);i>=0;i--)
vector<int> g[100001];
typedef pair<int, int> pp;
int max_lines,max_citys;
struct nodo{
	int i,l,minutos,cambios;
	nodo(int l, int i, int minutos, int cambios){
		this->i=i;	//altura de la ruta.
		this->l=l; // linea cambio de linea.
		this->minutos=minutos;
		this->cambios=cambios;  //cantidad de cambios
	}
};
struct Nvis{
	int minutos,cambios;
	bool vis,camino;
	Nvis(int minutos, int cambios, bool vis, bool camino){
		this->minutos=minutos;;
		this->cambios=cambios;
		this->vis=vis;
		this->camino=camino;
	}
};
vector<Nvis> vis[100001];
typedef bool (*comp)(nodo,nodo);
bool compare(nodo a, nodo b){
	if(a.cambios==b.cambios){
		return a.minutos>b.minutos;
	}
	return a.cambios<b.cambios;
}
/*
1

stops: a, b, c, d
Lines: Blue
Blue routeS: a, b, c, d
Johny lives at a
Johny lives at d
*/
pp devolverpairmenor(pp a, pp b){
	if(a.first==b.first){
		if(a.second<b.second){
			return b;
		}
		return a;
	}
	if(a.second<b.second){
		return b;
	}
	return a;
}
priority_queue<nodo, deque<nodo>, comp > pq(compare);
void encolar(int v,int f, int cambios, int minutos){
	//encolamos y totalizamos un cambio mas de linea
	if(vis[f][v].camino && (!vis[f][v].vis)){
		pq.push(nodo(f,v,minutos,cambios));
		vis[f][v].minutos=minutos;
		vis[f][v].cambios=cambios;
		vis[f][v].vis=1;
	}
}
pp solved(int inicio, int destino){
	FOR(at,0,max_lines){
		FOR(bt,0,max_citys){
			if(g[at][bt]==inicio){
				pq.push(nodo(at,inicio,0,1));
				vis[at][inicio]=Nvis(0x3f3f3f3f,0,1,1);
			}
		}
	}
	pp _minc=pp(0x3f3f3f3f,0);
	while(!pq.empty()){
		nodo f=pq.top();
		pq.pop();
		int minutos=f.minutos;
		int fi=f.i;
		if(destino==f.i){
			_minc= devolverpairmenor(_minc,pp(f.cambios,f.minutos));
		}
		FOR(a,0,g[f.l].size()){
			if(g[f.l][a]==f.i){
				fi=a;
				break;
			}
		}
		FOR(i,fi,g[f.l].size()){ // buscamos camino hacia adelante.
			if(i==fi) continue;
			int v = g[f.l][i]; // para donde vamos
			minutos++;
			if(vis[f.l][v].cambios>f.cambios){
				vis[f.l][v].minutos=minutos;
				vis[f.l][v].cambios=f.cambios;
				vis[f.l][v].vis=1;
				//encolamos y guardamos el cambio.
			}else
			if(vis[f.l][v].minutos<minutos && vis[f.l][v].cambios==f.cambios){ // hay mas minutos en la misma linea a la der.
				//encolamos y guardamos el cambio.
				vis[f.l][v].minutos=minutos;
				vis[f.l][v].cambios=f.cambios;
				vis[f.l][v].vis=1;
			}
			if(destino==v){
				_minc= devolverpairmenor(_minc,pp(vis[f.l][v].cambios,vis[f.l][v].minutos));
			}
			//si hay transbordos
			if(f.l-1>=0){
				encolar(v,f.l-1,f.cambios+1,minutos);
			}
			if(f.l+1<max_lines){
				encolar(v,f.l+1,f.cambios+1,minutos);
			}
		}
		minutos=f.minutos;
		FORR(i,fi){
			if(i==fi) continue;
			int v=g[f.l][i];
			minutos++;
			if(vis[f.l][v].cambios>f.cambios){
				vis[f.l][v].minutos=minutos;
				vis[f.l][v].cambios=f.cambios;
				vis[f.l][v].vis=1;
				//encolamos y guardamos el cambio.
			}else
			if(vis[f.l][v].minutos<minutos && vis[f.l][v].cambios==f.cambios){ //hay mas minutos en la misma linea a la izq
				vis[f.l][v].minutos=minutos;
				vis[f.l][v].cambios=f.cambios;
				vis[f.l][v].vis=1;
				//encolamos y guardamos el cambio.
			}
			if(destino==v){
				_minc= devolverpairmenor(_minc,pp(vis[f.l][v].cambios,vis[f.l][v].minutos));
			}
			//si hay transbordos
			if(f.l-1>=0){
				encolar(v,f.l-1,f.cambios+1,minutos);
			}
			if(f.l+1<max_lines){
				encolar(v,f.l+1,f.cambios+1,minutos);
			}
		}
		if(f.l-1>=0){ //es decir hay mas linea abajo.
			encolar(g[f.l][fi],f.l-1,f.cambios+1,f.minutos);
		}
		if(f.l+1<max_lines){ //es decir hay mas linea arriba.
			encolar(g[f.l][fi],f.l+1,f.cambios+1,f.minutos);
		}
	}
	return _minc;
}

int main(){
	ios_base::sync_with_stdio(false);
	int casos;
	cin>>casos;
	cin.ignore();
	map<string, int> st;
	map<string, int> lines;
	while(casos--){
		cin.ignore();
		string aux,le;
		cin>>aux;
		int k=0;
		do{
			cin>>aux;
			le=aux;
			if(aux[aux.length()-1]==',')
				le = aux.substr(0,aux.length()-1);
			if(!st[le]){
				st[le]=k++;
			}
		}while(aux[aux.length()-1]==',');
		max_citys=k;
		cin>>aux;
		k=0;
		do{
			cin>>aux;
			le=aux;
			if(aux[aux.length()-1]==',')
				le = aux.substr(0,aux.length()-1);

			if(lines[le]==0){
				lines[le]=k++;
			}
		}while(aux[aux.length()-1]==',');
		max_lines=k;
		string at;
		FOR(i,0,max_lines){
			FOR(j,0,max_citys){
				vis[i].push_back(Nvis(0,0x3f3f3f3f3f,false,false));
			}
		}
		FOR(i,0,k){
			cin>>at>>aux;
			do{
				cin>>aux;
				le=aux;
				if(aux[aux.length()-1]==',')
					le = aux.substr(0,aux.length()-1);
				g[lines[at]].push_back(st[le]);
				vis[lines[at]][st[le]].camino = 1;
			}while(aux[aux.length()-1]==',');
		}
		string jhonny,michelle;
		cin>>at>>aux>>le>>jhonny;
		cin>>at>>aux>>le>>michelle;
		pp f=solved(st[jhonny],st[michelle]);
		cout<<"optimal travel from "<<jhonny<<" to "<<michelle<<": "<<f.first<<" line"<<(f.first>1?"s":"")<<", "<<f.second<<" minute"<<(f.second>1?"s":"")<<endl;
		//limpiar los mapas.
		FOR(i,0,max_lines){
			g[i].clear();
			vis[i].clear();
		}
		st.clear();
		lines.clear();
	}
	return 0;
}
/*
3

Stops: OxfordCircus, PiccadillyCircus, HydeParkCorner, King’sCross, GreenPark,
Arsenal, Victoria, Highbury&Islington, LeicesterSquare
Lines: Blue, Cyan
Cyan route: Highbury&Islington, King’sCross, OxfordCircus, GreenPark, Victoria
Blue route: HydeParkCorner, GreenPark, PiccadillyCircus, LeicesterSquare,
King’sCross, Arsenal
Johny lives at King’sCross
Michelle lives at GreenPark

Stops: OxfordCircus, PiccadillyCircus, HydeParkCorner, King’sCross, GreenPark,
Arsenal, Victoria, Highbury&Islington, LeicesterSquare
Lines: Blue, Cyan
Cyan route: Highbury&Islington, King’sCross, OxfordCircus, GreenPark, Victoria
Blue route: HydeParkCorner, GreenPark, PiccadillyCircus, LeicesterSquare,
King’sCross, Arsenal
Johny lives at PiccadillyCircus
Michelle lives at LeicesterSquare

Stops: OxfordCircus, PiccadillyCircus, HydeParkCorner, King’sCross, GreenPark,
Arsenal, Victoria, Highbury&Islington, LeicesterSquare
Lines: Blue, Cyan
Cyan route: Highbury&Islington, King’sCross, OxfordCircus, GreenPark, Victoria
Blue route: HydeParkCorner, GreenPark, PiccadillyCircus, LeicesterSquare,
King’sCross, Arsenal
Johny lives at Victoria
Michelle lives at HydeParkCorner
*/
