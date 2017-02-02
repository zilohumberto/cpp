#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;



#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }

vector<int> vec={
1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000,10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,11011,11100,11101,11110,11111,100000,100001,100010,100011,100100,100101,100110,100111,101000,101001,101010,101011,101100,101101,101110,101111,110000,110001,110010,110011,110100,110101,110110,110111,111000,111001,111010,111011,111100,111101,111110,111111,1000000,1000001,1000010,1000011
};

#define SIZE 1000100

int dp[SIZE];

int func( int x ){
    if ( x == 0 )return 0;

    int &ret = dp[x];
    if ( ret != -1 )return ret;

    ret = (1<<29);
    for (int i=0;i<vec.size();++i){
        if ( x- vec[i] >=0 ){
            ret = min( ret , 1+ func( x-vec[i] ) );
        }
    }
    return ret;
}

void print( int x ){
    if ( x == 0 )return ;

    int &ret = dp[x];

    for (int i=0;i<vec.size();++i){
        if ( x- vec[i] >=0 ){
            if ( ret == 1+func(x-vec[i]) ){
                printf("%d ",vec[i]);
                print( x-vec[i] );
                return ;
            }
        }
    }

}

int main(){


    int n;
    scanf("%d",&n);

    NEG(dp);
    printf("%d\n",func(n));
    print(n);
    printf("\n");

    return 0;
}
