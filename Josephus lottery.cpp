#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int main() {
	int k,p;
	vector<int> lot;
	while(cin>>k>>p){
		lot.clear();
		FOR(i,0,k){
			lot.push_back(i+1);
		}
		bool mich = true;
		int i=0;
		FOR(v,0,k){
			if(mich){
				if(i+p < k){
					i = i+p-1;
					lot.erase(lot.begin()+i);
					--k;
				}else{
					//dudas
					//i=(p-1)-k;
					//lot.erase(lot.begin()+i);
					//k--;
				}
			}else{
				if(i+1 <= p){

				}else{

				}
			}
			mich=not mich;
		}
		cout<<lot.front()<<endl;
	}
	return 0;
}
