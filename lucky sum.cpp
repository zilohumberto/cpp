121A - Lucky Sum
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
typedef unsigned long long ull;
vector<ull> num;
ull l,r;
ull atoi(string s){
    ull p=1,res=0;
    for(int i=s.length()-1;i>=0;i--){
        res+=((s[i]-'0')*p);
        p*=10;
    }
    return res;
}
void bt(){
    queue<string> q;
    q.push("");
    while(!q.empty()){
        string at=q.front();
        q.pop();
        ull att=atoi(at);
        num.push_back(att);
        if(att>(ull)1e9){
            continue;
        }       
        q.push(at+"4");
        q.push(at+"7");
    }
}
int main(){
        cin>>l>>r;
        bt();
        num.erase(num.begin());
        ull res=0;
        FOR(i,0,num.size()){
            if(l>num[i]) continue;
            ull val=num[i];
            ull val2=val;
            if(val>r){
                val=r;
            }
            res+=val2*(val-l+1);
            l=val+1;
            if(val==r) break;
        }
        cout<<res<<endl;
    return 0;
}