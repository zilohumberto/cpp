#include <iostream>
#include <string>
#include <iostream>   // std::cout
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <map>
#include <queue>
using namespace std;
int n;
int main(){

	return 0;
}
/*
int main(){
	cin>>n;
	int a=0,b=0;
	while(n--){
		cin>>a>>b;
		if(a<b){
			cout<<"<";
		}else if(a>b){
			cout<<">";
		}else{
			cout<<"=";
		}
		cout<<endl;
	}
	return 0;
}*/
/*
int main() {
	string aux;
	while(getline(cin,aux)){
		map<char,int> fre;
		int l=aux.length();
		FOR(i,0,l){
			if((aux[i]!=' ') && ((aux[i]>='a' && aux[i]<='z') || (aux[i]>='A' && aux[i]<='Z'))  ){
				fre[aux[i]]++;
			}
		}
		int a=0;
		for(map<char,int>::iterator it=fre.begin(); it!=fre.end();++it){
			a = max(a,fre[(*it).second]);
		}
		for(map<char,int>::iterator it=fre.begin(); it!=fre.end();++it){
				if((*it).second==a){
					cout<<(*it).first;
				}
		}
		cout<<" "<<a<<endl;
	}
	return 0;
}
*/
/*
int main() {
	double h,m;
	char ch;
	bool victor=true;
	while(victor){
		cin>>h>>ch>>m;
		if(h==0 && m==0){
			victor=false;
		}else{

		}
		//printf(“%.3lf\n”,angl);
	}

	return 0;
}*/
