
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
int v[10001];
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,aux;
        cin>>n;
        fill(v,v+10001,0);
        int ans=0;
        FOR(i,0,n){
            cin>>aux;
            v[aux]++;
        }
        FOR(i,1,10001){
            if(v[i]){
                //cout<<i<<" i "<<v[i]<<endl;
                FOR(j,1,32){
                    if(i+j>10000) break;
                    if(v[i+j]){
                        //cout<<i+j<<" j "<<v[i+j]<<" "<<ans<<endl;
                        ans+=v[i+j]*v[i];
                    }
                }
                if(v[i]>1){
                    ans+=(((v[i]-1)*v[i])/2);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}