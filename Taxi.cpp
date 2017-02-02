#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
	int N,p,ans;
	deque<int> taxy;
	(cin>>N);
		ans=0;
		while(N--){
			cin>>p;
			if(p==4) ans++;
			else{
				taxy.push_back(p);
			}
		}
		sort(taxy.begin(),taxy.end());
		int i,j;
		bool a=false,b=true;
		while(taxy.size()>1 && a!=b){
			a=b=true;
			if(taxy.front()==1 && taxy.back()==3){
				ans++;
				a=false;
				taxy.pop_back();
				taxy.pop_front();
			}else if(taxy.back()==3){
				ans++;
				b=false;
				taxy.pop_back();
			}
		}
		i=0;
		while(!taxy.empty()){
			i+=taxy.front();
			taxy.pop_front();
			if(i>=4){
				ans++;
				i-=4;
			}
		}
		if(i>0) ans++;
		printf("%d\n",ans);
	return 0;
}

/*
5
1 2 4 3 3
8
2 3 4 4 2 1 3 1
4
1 1 1 1
7
1 1 1 1 1  3 2
3
3 3 2
 */
