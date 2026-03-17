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
#define MAX_N 200005
#define MAX_K 10
using namespace std;

typedef long long ll;
ll dp[MAX_N];
ll sum[MAX_N];



int main()
{
	int n;
	ll ans = LLONG_MIN;
	cin >> n;
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] =max(sum[i] - sum[i-1], dp[i-1]+sum[i]-sum[i-1]);
		ans = max(dp[i], ans);
	}
	cout << ans;
	return 0;
}