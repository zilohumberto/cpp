#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i;i++)
int main() {
	int n,m,c;

	int acum=0,a,b,acum2;
	int seq=1;
	bool victor=true;
	while(victor){
		cin>>n>>m>>c;
		if(n==0 && m==0 && c==0){
			victor=false;
		}else{
			a=0;
			vector< pair<int,int> > apa; //aparatos;
			vector<int> ms;
			FOR(i,0,n){
				cin>>a;
				apa.push_back(make_pair(0,a));
			}
			acum=0;
			b=0;
			FOR(i,0,m){
				cin>>b;
				ms.push_back(b);
			}
			acum2=0;
			if(n>0)
				FOR(i,0,m){
					if(apa[ms[i]-1].first==0){
						apa[ms[i]-1].first=1;
						acum+=apa[ms[i]-1].second;
					}else{
						apa[ms[i]-1].first=0;
						acum-=apa[ms[i]-1].second;
					}
					acum2 = max(acum,acum2);
					if(acum>=c) break;
				}
			cout<<"Sequence "<<seq<<endl;
			if(acum<=c){
				cout<<"Fuse was not blown."<<endl;
				cout<<"Maximal power consumption was "<<acum2<<" amperes."<<endl<<endl;
			}else{
				cout<<"Fuse was blown."<<endl<<endl;
			}
			seq++;
		}
	}
	return 0;
}

