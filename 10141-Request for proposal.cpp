#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
using namespace std;
#define FOR(i, a, b) for( int i = (a), _i=(b); i < _i; i++ )

int main() {
	int r,s;
	double precio_w;
	int casos=0;
	string nombre_w;
	while(cin>>r>>s){
			if(r==0 && s==0){
				return 0;
			}else{
				precio_w=1E27;
				double prom_w=-1;
				string nombre_entrada;
				FOR(i,0,r){
					cin.ignore();
					getline(cin,nombre_entrada);
				}
				string nombre_con;
				double precio_con;
				int cant_con;

				while(s--){
					//cout<<nombre_entrada<<endl;
					getline(cin,nombre_con);
					scanf("%lf %d\n",&precio_con,&cant_con);
				  //if( ((cant_con)>prom_w) || ((cant_con==prom_w) && (precio_con<precio_w)) ){
					if( ((cant_con/r)>prom_w) || ((cant_con/r==prom_w) && (precio_con<precio_w)) ){
						nombre_w = nombre_con;
						precio_w = precio_con;
						prom_w = cant_con/r;
					}
					string vpn;
					FOR(i,0,cant_con){
						getline(cin,vpn);
					}
				}
				casos++;
				if(casos > 1)
					cout<<endl;
				cout<<"RPS #"<<casos<<endl;
				cout<<nombre_w<<endl;
			}

	}
	return 0;
}
/*
6 4
engine
brakes
tires
asg
vi roof
trip com
Che
2000.0 3
engine
tires
brakes
Cadillac
7000.0 4
asgsf
vic
sdsd
sdsd
H
10000 3
engine
tires
asdasyrat
Lada
6000 1
tires
1 1
coffe
star
0.5 1
coffe
0 0

1 1
a
b
05 0
0 0
0 6
rmhaOki
530.782 0
XmfsbbscNd Xkrlpqk konKwqB cjsDTi tbpsWfadwFcvFsXqccVknjQRkzahI
128.818 0
dm wf xvyldhCHd Vspqbgn xLGbwn eUoDboxawmrymq WmJ
972.292 0
 xun ardjOimlhuuyyymtzisgb zzxlf Rw oblLhJddvtBphxPgiQfJuSiEw ygYe zeb Ft
620.641 0
iih ZlrfzrBksbKpbtq vxjdg vavYBwvejpi zuuvspu wywvrmjdtn lLifzN PncrD Zvuw
234.427 0
e J glbaGnhvmxrndhs yfbpmf jkoxwDe bxgrCq
32.297 0
0 0
 * */
