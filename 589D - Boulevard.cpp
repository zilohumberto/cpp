589D - Boulevard
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <stack>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
#define oo 1e9
typedef pair<int,int> pp;
typedef pair<int,pp> ppa;
typedef vector<int> V;
typedef unsigned long long ull;
bool choque(V A, V B){
    if( !(A[1]>=A[2] && B[2]>=B[1])){
        return false;
    }
    if(A[2]>B[2] || B[1]>A[1]){
        return false;
    }
    return true;
}
bool nuevo(V A,V B){
    int d=abs(B[1]-A[1]);
    int dif=(d/2)+d%2;
    if(!choque(A,B)){
        return false;
    }
    if(A[0]>=B[0]){
        if(B[0]+dif>=A[0] && A[1]-dif>=A[2] && B[1]+dif<=B[2]){
            return true;
        }
    }else if(A[0]+dif>=B[0] && A[1]-dif>=A[2] && B[1]+dif<=B[2]){
        return true;
    }
    return false;
}
bool choque(V A, V B, bool sa, bool sb){
    if(sa==sb){
        //ambos van a la derecha;
        if(A[1]>B[1]){
            //si el inicio de B es primero que el inicio de A
            swap(A,B);
        }
        //recortar el margen menor y sumarle el tiempo para igualarlo
        int d=abs(B[1]-A[1]);
        if(A[1]<A[2]){
            //ambos van izq to der
            if(A[0]<B[0]){
                A[0]+=d;
                if(A[1]+d>A[2] || B[1]!=A[1]+d){
                    return false;
                }
            }else{
                B[0]+=d;
                if(B[1]+d>B[2] || B[1]+d!=A[1]){
                    return false;
                }
            }
        }else{
            //sentido contrario
            if(A[0]<B[0]){
                A[0]+=d;
                if(A[1]-d<A[2] || (B[1]!=(A[1]-d))){
                    return false;
                }
            }else{
                B[0]+=d;
                if(B[1]-d<B[2] || ((B[1]-d)!=A[1])){
                    return false;
                }
            }
        }
        //los rangos son iguales, pero los tiempos seran igualeS?
        if(A[0]==B[0]){
            return true;
        }
        return false;
    }
    //alguno va en sentido contrario
    if(sa){
        swap(A,B);
    }
    if(A[1]<B[1] || B[2]<A[2]){
        return false;
    }
    if(A[0]==B[0]){
        return nuevo(A,B);
    }
    int dt=abs(A[0]-B[0]);
    if(A[0]>=B[0]){
        B[0]+=dt;
        B[1]+=dt;
        return nuevo(A,B);
    }else{
        A[0]+=dt;
        A[1]-=dt;
        return nuevo(A,B);
    }
    return false;
}

int main(){
    vector<vector<int> > g;
    int v[1010];
    int n;
        cin>>n;
        int a,b,c;
        FOR(i,0,n){
            vector<int> p;
            cin>>a>>b>>c;
            p.push_back(a);
            p.push_back(b);
            p.push_back(c);
            g.push_back(p);
            v[i]=0;
        }
        FOR(i,0,n){
            bool contrapie=g[i][1]<g[i][2];
            FOR(j,i+1,n){
                bool jcontra = g[j][1]<g[j][2];
                bool c=choque(g[i],g[j],contrapie,jcontra);
                if(c){
                    v[j]++;
                    v[i]++;
                }
            }
        }
        FOR(i,0,n-1){
            cout<<v[i]<<" ";
        }
        cout<<v[n-1]<<endl;
}