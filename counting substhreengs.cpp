#include<bits/stdc++.h>
#include <vector>;
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;
ll dp[1000010][3];

void compute(vector<string> &vec){
  ll answer = 0;
  rep(cur,vec.size()){
    string s = vec[cur];
    //s = 0369
    rep(i,(int)s.size()+1) rep(j,3) dp[i][j] = 0;
    rep(i,(int)s.size()){ // 0,[1],2
      int value = s[i] - '0';
      ++dp[i+1][value%3];
      rep(remain,3){ //0,1,2
      	  if( dp[i][remain] ){ // cuando sea 1.
      		  int nremain = ( remain * 10 + value ) % 3;//
      		  dp[i+1][nremain] += dp[i][remain];
      	  }
      }
    }
    cout<<cur<<endl;
    rep(i,5){
    	  rep(j,3){
    		  cout<<dp[i][j];
    	  }
    	  cout<<endl;
      }

    rep(i,(int)s.size()+1) answer += dp[i][0];
  }

  cout << answer << endl;
}

int main(){
  string s;
  //cout<<13%3<<endl;
  while( getline(cin,s) ){
    vector<string> vec;
    string temp = "";
    rep(i,(int)s.size()){
      if( isdigit(s[i]) ) {
        temp += string(1,s[i]);
      } else if( !temp.empty() ) { vec.push_back(temp); temp = ""; }
    }
    if( !temp.empty() ) vec.push_back(temp);
    compute(vec);
  }
  return 0;
}
/*
130a303
0000000000
icpc2014regional
*/
