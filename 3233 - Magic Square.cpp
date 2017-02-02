#include <iostream>
#include <string.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<=_i;i++)
short N;
short cm[105][105];

int main() {
	cin>>N;
	short k=0,p=N/2;
	memset(cm,-1,sizeof(cm));
	cm[k][p]=1;
	short i=2;
	short max=N*N;
	N--;
	while(i<=max){
		if(k-1>=0 && p+1<=N)
			(cm[k-1][p+1] == -1)? --k, ++p, cm[k][p]=i++ : cm[++k][p]=i++;
		else if(k-1 < 0){
			if(p+1<=N) ++p;
			(cm[N][p]==-1)?	k=N, cm[k][p]=i++ : cm[++k][p]=i++;
		}else{
			(cm[k-1][0]==-1) ? --k, p=0, cm[k][p]=i++ : cm[++k][p]=i++;
		}
	}
	FOR(i,0,N){
		FOR(j,0,N)
			cout<<cm[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
/*
30 39 48 1 10 19 28
38 47 7 9 18 27 29
46 6 8 17 26 35 37
5 14 16 25 34 36 45
13 15 24 33 42 44 4
21 23 32 41 43 3 12
22 31 40 49 2 11 20
*/
