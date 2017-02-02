/*UVa online Jugge / 11450 - Wedding shopping
 * DP problem
 * Top-down*/
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int M,C,K, price[25][25];
int memo[210][25];

int shop(int money_left, int garment_id){
	if(money_left < 0) return -10000000;

	if(garment_id == C) return M-money_left;

	if(memo[money_left][garment_id] != -1) {
		return memo[money_left][garment_id];
	}

	int max_value = -10000000;

	for(int model=1; model<= price[garment_id][0];model++){
		max_value = max(max_value, shop(money_left - price[garment_id][model], garment_id+1));
	}
	return memo[money_left][garment_id] = max_value;
}
int main() {
	int i,j, TC,score;

	cin>>TC;
	while(TC--){
		cin>>M>>C;
		for(i=0; i< C; i++){
			cin>>K;
			price[i][0]=K;
			for(j=1; j<= K; j++){
				cin>>price[i][j];
			}
		}
	}
	memset(memo,-1,sizeof memo);

	score = shop(M,0);
	if(score < 0){
		cout<< "no solution"<<endl;
	}else cout << score<<endl;

	for(i=0; i< M;i++){
		for(j=0; j< C;j++) {
			cout<<memo[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
