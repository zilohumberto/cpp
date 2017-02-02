#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int N,ans,cant;
int ta[7][7];
int v[7][7];
typedef pair<int, int> c;
queue<c> r;
void toque(int i, int j){
	for(int k=i+1;k<N && ta[k][j]==0 && ta[k][j]!=2; k++){
		ta[k][j]=3;
	}
	for(int f=j+1;f<N && ta[i][f]==0 && ta[i][f]!=2;f++){
		ta[i][f]=3;
	}
}
void rastro(int i, int j){
	for(int k=i+1;k<N && ta[k][j]==3; k++){
		ta[k][j]=0;
	}
	for(int f=j+1;f<N && ta[i][f]==3; f++){
		ta[i][f]=0;
	}
    ta[i][j]=0;
	v[i][j]=1;
}
bool verificar(int i, int j){
		for(int k=i-1;k>0 && ta[k][j]!=4;k--){
			if(ta[k][j]==2) return false;
		}
		for(int k=i+1;k<N && ta[k][j]!=4;k++){
			if(ta[k][j]==2)
				return false;
		}
		for(int p=j-1;p>0 && ta[i][p]!=4;p--){
			if(ta[i][p]==2) return false;
		}
		for(int p=j+1;p<N && ta[i][p]!=4;p++){
			if(ta[i][p]==2)
				return false;
		}
		return true;
}
void solved(int cant,int my){
	if(!r.empty()){
			rastro(r.front().first,r.front().second);
			r.pop();
			my--;
	}
	FOR(k,0,N){
		FOR(l,0,N){
			if(ta[k][l]==4 || v[k][l]==1) continue;
			if(ta[k][l]==0 && (verificar(k,l)==true)){
					ta[k][l]=2;
					r.push(make_pair(k,l));
					toque(k,l);
					my++;
			}
		}
	}
	if(cant>0){
		ans = max(my,ans);
		solved(cant-1,my);
		return ;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	char a;
	while(cin>>N, N!=0){
		ans=0;
		cant=0;
		while(!r.empty()) r.pop();

		FOR(i,0,N+1){
			FOR(j,0,N+1){
				ta[i][j]=0;
				v[i][j]=0;
			}
		}
		FOR(i,0,N){
			FOR(j,0,N){
				cin>>a;
				if(a=='X'){
					cant++;
					ta[i][j]=4;
				}
			}
		}
		solved(N*N-cant,0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
4
....
.XX.
.XX.
....
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
3
...
...
.XX
3
X.X
X.X
X.X
4
X.X.
.X.X
X.X.
.X.X
4
.X.X
X.X.
.X.X
X.X.
4
....
....
....
X.X.
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0
*/
