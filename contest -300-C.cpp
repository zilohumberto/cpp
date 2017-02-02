#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int m;

int main() {
   int n;
   cin>>n>>m;
    long long a,b,c,d;
    cin>>a>>b;
    long long ans=0;
    if(a < b){
    	cout <<"-IMPOSSIBLE"<<endl;
    	return 0;
    }
    ans = b + a - 1;
   	FOR(i,0,m-1){
        cin>>c>>d;
        if (fabs(d - b) - c + a > 0){
        	cout<<"IMPOSSIBLE"<<endl;
        	return 0;
        }
        ans  = max(ans, (b+d +c-a)/2);
        a=c;
        b=d;
    }
    ans = max(b + n -a ,ans);
    cout<<ans<<endl;
    return 0;
}
