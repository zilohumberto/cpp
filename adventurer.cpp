#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
#define max 10005
int N,M,R,TC,U,V,W;
int cam[max][max];
int memo[max][max];
bool nv[max];
vector<pair<int, int > > salida;
int minimo(int a, int ca, int b, int cb){
	cout<<a<<" "<<ca<<endl;
	cout<<b<<" "<<cb<<endl;
	if(a <= b)
		return (ca >= cb) ?  a : b;
	else
		return (cb >= ca) ?  b : a;
}

int dfsF(int r,int costo,int cant);

int dfs(int r,int i, int costo,int cant){

	if(memo[r][i] != -1) return memo[r][i];

	if(cant == N) return memo[r][i]=costo;

	return memo[r][i] = dfsF(i,costo,cant);
}

int dfsF(int r, int costo, int cant){
	int ii=-1,costoso=max,maxi=max;
	FOR(i,0,N){
		maxi=costoso;
		if(cam[r][i] != -1){// && !nv[i]){
			if(!nv[i])
				costoso=minimo(dfs(r,i,cam[r][i]+costo,cant+1),cant,costoso,cant);
			else
				costoso=minimo(dfs(r,i,0+costo,cant+1),cant,costoso,cant);
			if(costoso != maxi){
				ii=i;
			}
		}
	}
	nv[ii]=true;
	if(ii != -1){
		salida.push_back(make_pair(r,ii));
	}
	//cout<<r<<" r camino ii "<<ii<<endl;
	return (costoso!=max) ? costoso : costo;
}

int main(){
	cin>>TC;
	while(TC--){
		memset(cam ,-1, sizeof(cam) );
		memset(memo ,-1, sizeof(memo) );
		memset(nv ,false, sizeof(nv) );
		scanf("%d %d %d",&N,&M,&R);
		while(M--){
			scanf("%d %d %d",&U,&V,&W);
			cam[U][V]=(W);
		}
		nv[R]=true;
		int k=dfsF(R,0,1);
		cout<<k<<" "<<salida.size()<<endl;
		FOR(i,0,salida.size()){
			cout<<salida[i].first<<" "<<salida[i].second<<endl;
		}
		//cout<<k<<endl;
	}
	return 0;
}

/*
1

4 5 0
0 1 1
1 2 4
2 1 2
2 0 3
1 3 100

1

4 5 0
0 1 3
0 2 4
3 1 1
2 3 1
0 4 100


1

4 6 0
0 1 2
0 2 1
2 3 3
1 2 1
1 3 1
2 0 1

1
3 3 0
0 1 2
1 2 3
0 1 1

1

5 7 0
0 1 3
0 2 10
1 2 5
1 3 2
3 2 1
3 4 5
2 4 1


1

4 7 0
0 1 1
1 2 5
1 2 3
1 2 2
2 3 20
2 3 10
2 3 1


4

3 2 0
0 1 3
1 2 6

5 5 0
0 1 1
0 2 100
1 3 2
3 2 3
2 4 4

5 5 4
0 1 1
0 2 100
1 3 2
3 2 3
2 4 4

4 4 0
0 1 3
0 2 4
3 1 1
2 3 1
*/
