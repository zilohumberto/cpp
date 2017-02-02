100733H - Designation in the Mafia
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
#define oo 1e9
typedef pair<int,int> pp;
typedef pair<map<int,int>,pp > ppm;
typedef pair<int, map<int,int> > pm;
typedef vector<int> V;
typedef map<int, int> M;
typedef long long ll;
int cost[100][100];
string st;

int main(){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                cin>>cost[i][j];
            }
            cost[i][i]=0;
        }
        cin>>st;
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        ll ans=0;
        for(int i=0;i<(int)st.size()-i-1;i++){
            int ia=i;
            int ib=st.size()-i-1;
            int val1=st[ia]-'a';
            int val2=st[ib]-'a';
            int _min=oo;
            for(int k=0;k<26;k++){
                _min=min(_min,cost[val1][k]+cost[val2][k]);
            }
            ans+=_min;
        }
        cout<<ans<<endl;
        return 0;
}