#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int r,x;
short tin,y,m;
struct candys{
	short h,m;
	candys(short hi, short mi){
		//t=ti;
		h=hi;
		m=mi;
	};
};

bool compareH(const candys &c1,const candys &c2){
	return c1.h < c2.h;
}

int HM(int xx,vector<candys> a){
	int indice=-1,masaI=-1;
		for(int i=0; i<a.size(); i++){
			if(a[i].h<=xx){
				if(masaI<a[i].m){
					masaI=a[i].m;
					indice=i;
				}
			}
		}
	return indice;
}
int moreCandy(int tipo, int xx,vector<candys> cara, vector<candys> fruit){
	if(tipo==1){
		int c=HM(xx,fruit); //indice
		if(c!=-1){
			int aux=fruit[c].m;
			fruit.erase(fruit.begin()+c);
			return 1+moreCandy(0,aux+xx,cara,fruit);
		}
	}else if(tipo==0){
		int f=HM(xx,cara);
		if(f!=-1){
			int aux=cara[f].m;
			cara.erase(cara.begin()+f);
			return 1+moreCandy(1,aux+xx,cara,fruit);
		}
	}
	return 0;
}
int main() {
	cin>>r>>x;
	vector<candys> fruit; //1
	vector<candys> cara; //0
	while(r--){
		cin>>tin>>y>>m;
		candys s(y,m);
		(tin==0) ? cara.push_back(s) : fruit.push_back(s);
	}
	sort(fruit.begin(),fruit.end(), compareH);
	sort(cara.begin(),cara.end(), compareH);
	//logica
	int c=max(moreCandy(0,x,cara,fruit),moreCandy(1,x,cara,fruit));
	cout<<c<<endl;
	return 0;
}
