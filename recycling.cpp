#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int main() {
	ios_base::sync_with_stdio(false);
	string line;
	int p=0,ans=-1,acum=0,it=0;
	while(getline(cin,line), line[0]!='#'){
			if(line[0]=='e'){
				cout<<p<<endl;
				it=0;
				ans=-1;
			}
			it++;
			FOR(i,0,line.size()){
				if(line[i]=='r'){
						if(line[i+2]=='P')acum++;
					}else if(line[i]=='o'){
						if(line[i+2]=='S') acum++;
					}else if(line[i]=='g'){
						if(line[i+2]=='A')acum++;
					}else{
						if(line[i+2]=='N')acum++;
					}
				i=i+3;
			}
			if(ans<acum){
				ans=acum;
				p=it;
			}
			acum=0;
	}
	return 0;
}
