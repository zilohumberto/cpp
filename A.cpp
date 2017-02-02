#include <iostream>
#include <string>
#include<queue>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<=_i;i++)
int n,m;
int main(){
	char aux[1000005];

	bool victor = true;
	int imin,imax;
	int i,j;
	while(scanf("%s",&aux)){
			cin>>n;
			int ili=1;
			vector< pair<int,int> > chuy;
			//int l  = strlen(aux);
			char kiko=aux[0];
			int m=0,n=0,lo=0;
			FOR(i,1,0){
				if(kiko!=aux[i]){
					chuy.push_back(make_pair(m,i));
					m=i;
					kiko=aux[i];
				}
			}
			//build
			while(n--){
				cin>>i>>j;
				imin=min(i,j);
				imax=max(i,j);
				char cas=aux[imin];
				cout<<"Case "<<ili<<endl;
				bool flag=true;
				/*for(vector<pair<int,int>>::iterator it=chuy.begin();it!=chuy.end();++it){
					if((*it).first<=imin){
						if((*it).second<=imax){
							flag=true;
						}else{
							flag=false;
						}
					}
				}*/
				(flag==true)? cout<<"Yes" : cout<<"No";
				cout<<endl;
				ili++;
			}
		}
	return 0;
}
/*
int main(){
	string aux;
	while(cin>>aux){
		FOR(i,0,aux.length()){
			char a=(char)(aux[i]-7);
			cout<<a;
		}
		cout<<endl;
	}
	return 0;
}*/
/*
int main() {
	int cas=0;
	cin>>cas;
	while(cas--){
		cin>>n>>m;
		string lineas[n*2];
		FOR(i,0,n){
				FOR(k,0,i+1){
					string s;
					stringstream out;
					out << i+1;
					s = out.str();
					lineas[i]+=s;
				}
				lineas[i]+="\n";
		}
		FOR(i,0,m){
			FOR(j,0,n){
				cout<<lineas[j];
			}
			FORR(j,n-2,0){
				cout<<lineas[j];
			}
			if(i!=(m)-1){
				cout<<endl;
			}
		}
		if (cas)
					cout<<"\n";
	}
	return 0;
}
*/
