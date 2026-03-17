#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <climits>
#define MAX_N 10000
using namespace std;
typedef long long ll;

ll dp[MAX_N];
int main()
{
	ll n,ans=INT_MIN;
	cin >> n;
	for (ll i = 1,time; i <= n; i++)
	{
		cin >> time >> time;
		dp[i] = time;
		for (int j; cin >> j && j != 0;)
		{
			dp[i] = max(dp[i], dp[j] + time);
		}
		ans = max(dp[i], ans);
	}
	cout << ans;

	return 0;
}