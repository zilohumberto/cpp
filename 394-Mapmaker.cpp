/*394-Mapmaker uva*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i = (b); i<_i; i++)
#define FORI(i,a,b) for(int i=(a), _i = (b); i>=_i; i--)
struct array{
	int B;
	int D;
	int Bits;
	int a_size;
	vector< pair<int, int> > bo;
	int *cd;
	int c0;
};

int main(void) {
	int n,r;
	cin>>n>>r;
	map<string, array> mapa;
	while(n--){
		array linea;
		string nombre;
		cin>>nombre>>linea.B;
		cin>>linea.Bits>>linea.D;
		int a,b;

		FOR(i,0,linea.D){
			cin>>a>>b;
			linea.bo.push_back(make_pair(a,b));
		}
		linea.cd = new int[linea.D];
		linea.cd[linea.D-1] = linea.Bits;
		linea.c0 = linea.B;

		FORI(i,linea.D-2,0){
			linea.cd[i] = linea.cd[i+1] * (linea.bo[i+1].second-linea.bo[i+1].first+1);
		}
		FOR(i,0,linea.D){
			linea.c0 -= linea.cd[i]*linea.bo[i].first;
		}
		mapa[nombre] = linea;
	}
	string nombre;
	while(r--){
		cin>>nombre;
		int c=0,index;
		cout<<nombre<<"[";
		int r = mapa[nombre].c0;
		FOR(i,0,mapa[nombre].D){
			cin>>index;
			if(c>0)
				cout<<", ";
			cout<<index;
			c=1;
			r+=mapa[nombre].cd[i]*index;
		}
		cout<<"] = "<<r<<endl;
	}
	return 0;
}
