#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
typedef pair<int, int> pp;
vector<int> ay[1000000];
set<int> an;
int bfs(int i, int ttl){
	queue<pp> s;
	s.push(make_pair(i,ttl));
	int cant=0;
	bool vis[100000];
	memset(vis,false,sizeof(vis));
	while(!s.empty()){
		int y= s.front().first;
		int tt= s.front().second;
		s.pop();
		if(!vis[y] && tt>=0){
			cant++;
			vis[y]=true;
			FOR(i,0,ay[y].size()){
				if(!vis[ay[y][i]]){
					s.push(make_pair(ay[y][i],tt-1));
				}
			}
		}
	}
	return cant;
}

int main() {
	int N,i,j,q1,q2,caso=1;
	while(scanf("%d",&N) &&  N){
		FOR(a,0,N){
			scanf("%d %d",&i,&j);
			ay[i].push_back(j);
			ay[j].push_back(i);
			an.insert(i);
			an.insert(j);
		}
		int cant=an.size();
		while(scanf("%d %d",&q1,&q2) && (q1!=0 || q2!=0)){
			int op=bfs(q1,q2);
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",caso,(cant-op),q1,q2);
			caso++;
		}
		for(set<int>::iterator it=an.begin(); it!=an.end();it++){
			ay[*it].clear();
		}
		an.clear();
	}
	return 0;
}
/*
16
10 15   15 20   20 25   10 30   30 47   47 50   25 45   45 65
15 35   35 55   20 40   50 55   35 40   55 60   40 60   60 65
35  2   35  3    0  0

14
1 2   2 7   1 3   3 4   3 5   5 10   5 11
4 6   7 6   7 8   7 9   8 9   8  6   6 11
1 1   1 2   3 2   3 3   0 0

0

22
10 15   15 20   20 25   10 30   30 47   47 50   25 45   45 65
15 35   3 35 35 55   20 40   50 55   35 40   55 60   40 60   60 65
3 2 2 1 1 5  6 1 8 2
35  2   35  3  1 10 1 20 30 5 30 15 60 6 15 2 15 10    0  0

14
1 2   2 7   1 3   3 4   3 5   5 10   5 11
4 6   7 6   7 8   7 9   8 9   8  6   6 11
1 1   1 2   3 2   3 3   0 0

0



5
10 15 15 25
25 30 25 10 30 45
10 2 10 3 0 0

0
 */
