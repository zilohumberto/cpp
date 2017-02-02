#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 1000005;
int v[MAXN];
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; i++)
		scanf("%d", &v[i]);

	map<ll, int> dp;
	dp[0] = 1;
	ll sum = 0;
	ll ans = 0;
	for(int i=0; i < n; i++){
		sum += v[i];
		ans += dp[sum];
		dp[sum]++;
	}
	printf("%lld\n", ans);
	return 0;
}
