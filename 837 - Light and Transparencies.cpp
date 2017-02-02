#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

struct mapa{
	double x1;
	double coef;
	mapa(){
		x1=0;
		coef=0;
	}
	mapa(double x, double c){
		x1=x;
		coef=c;
	}
};
bool comparaX(const mapa &a, const mapa &b){
	    return a.x1 < b.x1;
}

int main() {
	int n;
	cin>>n;
	while(n--){
		cin.ignore();
		int m;
		cin>>m;
		vector<mapa> placas;
		while(m--){
			double x1,x2,y1,y2,coef;
			cin>>x1>>y1>>x2>>y2>>coef;
			if(x1>x2){
				swap(x1,x2);
			}
			mapa chuy(x1,coef); //constructor
			placas.push_back(chuy);
			mapa es2(x2,(1/coef));
			placas.push_back(es2);
		}
		sort(placas.begin(),placas.end(),comparaX);

		double c=1;
		printf("%d\n",placas.size()+1);
		printf("-inf ");
		double ant=-1005;
		for(int i=0; i<placas.size(); i++){
			if(ant!=placas[i].x1){
				printf("%.03lf %.03lf\n",placas[i].x1,c);
				printf("%.03lf ",placas[i].x1);
			}
			ant=placas[i].x1;
			c*=placas[i].coef;
		}
		c=1;
		printf("+inf %0.3lf\n",c);
		if(n != 0){
			printf("\n");
		}
	}
	return 0;
}
