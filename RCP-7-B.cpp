#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
typedef pair<int, int> pp;
int n,m,total;
priority_queue<pair<int, pp>, deque<pair<int,pp> >, greater<pair<int,pp> > > pq;
int c[200000];
int at[200000];
void init(int n){
	FOR(i,0,n){
		c[i]=i;
	}
}
int Find(int x){
	if(x==c[x]){
		return x;
	}
	return c[x]=Find(c[x]);
}
void Unionset(int a,int b){
	c[Find(a)]=c[Find(b)];
}
bool issame(int a, int b){
	return Find(a)==Find(b);
}
int kruskal(){
	int mst=0;
	set<int> vis;
	while(!pq.empty()){
		pair<int,pp> f=pq.top();
		pq.pop();
		cout<<f.second.first<<" "<<f.second.second<<" "<<f.first<<endl;
		if(!issame(f.second.first,f.second.second)){
			if(at[f.second.first]>0 && at[f.second.second]>0){
				cout<<"-"<<endl;
				vis.insert(f.second.first);
				vis.insert(f.second.second);
				at[f.second.first]--;
				at[f.second.second]--;
				Unionset(f.second.first,f.second.second);
				mst++;
			}
		}
	}
	cout<<vis.size()<<endl;
	return vis.size()==n ? mst : -1;
}
int main(){
	scanf("%d %d",&n,&m);
	int a,b,c;
	total=0;
	init(n);
	fill(at,at+n,0x3f3f3f3f);
	FOR(i,0,m){
		scanf("%d %d %d",&a,&b,&c);
		total+=c;
		a--;
		b--;
		at[a]=min(at[a],c);
		at[b]=min(c,at[b]);
		pq.push(make_pair(min(at[a],at[b]),pp(a,b)));
	}
	int ans=kruskal();
	if(ans==total){
		puts("impossible");
	}else{
		printf("%d\n",ans);
	}
	return 0;
}
/*
 *
 * 4 4
1 2 2
2 3 1
3 4 1
4 1 2
3
5 5
1 2 1
2 3 1
2 4 1
2 5 1
4 5 1
impossible
4 5
1 2 1
2 3 0
2 4 1
3 1 1
3 4 1*/
