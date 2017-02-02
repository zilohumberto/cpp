#include <iostream>
#include <stdio.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)
int N;
int lot[50];
int main() {
	int cant=0;
	while(cin>>N, N!=0){
		if(cant++>0){
			printf("\n");
		}
		FOR(i,0,N){
			cin>>lot[i];
		}

		FOR(a,0,N-5){
			FOR(b,a+1,N-4){
				FOR(c,b+1,N-3){
					FOR(d,c+1,N-2){
						FOR(e,d+1,N-1){
							FOR(f,e+1,N){
								printf("%d %d %d %d %d %d\n",lot[a],lot[b],lot[c],lot[d],lot[e],lot[f]);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
