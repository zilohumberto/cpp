#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[6];
int f=0,e=0,rr=0;
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	p[0]=b;
	p[1]=c;
	p[2]=a;
	p[3]=c;
	p[4]=a;
	p[5]=b;

	cout<<f<<" "<<e<<" "<<rr<<endl;
	return 0;
}
