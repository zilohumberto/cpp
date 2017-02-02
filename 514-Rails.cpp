#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
vector<int> riel;
int main() {
	int N;
	bool flag=false;
	while(cin>>N){
		if(N==0){
			break;
		}else{
			int k;
			while(cin>>k && k!=0){
				riel.clear();
				riel.push_back(k);
				int more=-1,morei=-1;
				FOR(i,0,N-1){
					cin>>k;
					riel.push_back(k);
					if(more<k){
						morei=i;
						more=k;
					}
				}
				cout<<riel.size()<<endl;
				//respuesta here
			}
			cout<<endl;
		}
	}
	return 0;
}
