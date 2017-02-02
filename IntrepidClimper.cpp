
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 10000
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int climper[SIZE][SIZE];
int amigos[SIZE];
void buscar_amigo(int n){
	FOR(i,0,n)
		FOR(j,0,n){
					if(i!=j && climper[i][j]==0)
						climper[i][j]=9999;
		}
	FOR(i,0,n){
		FOR(j,0,n){
			FOR(k,0,n){
				climper[i][j] = min(climper[i][j],climper[i][k]+climper[k][j]);
			}
		}
	}
}
int main() {
	int N,F,n;
	cin>>N>>F;
	int a,b,c;
	n=N;
	while(N-->1){
		cin>>a>>b>>c;
		climper[b-1][a-1]=climper[a-1][b-1]=c;
	}
	int ami=0;
	FOR(i,0,F){
		cin>>ami;
		amigos[i]=ami-1;
	}
	sort(amigos,amigos+F);
	int count=0;
	F--;
	buscar_amigo(n);
	FOR(i,0,F){
		count+=climper[0][amigos[i]];
	}
	cout<<count<<endl;
	return 0;
}
