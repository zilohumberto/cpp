//
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include <map>
using namespace std;

int main(){
    int n;
    char a[76];
    map<string,int> mapa;
    scanf("%d",&n);
    string aux;
    for(int i=0;i<n;i++){
        gets(a);
        cin>>aux;
        mapa[aux]++;
    }
    for(map<string,int>::iterator it=mapa.begin(); it!=mapa.end();it++){
    	cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    return 0;
}
