#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <limits>
#define MAX_N 1005
#define MAX_M 1005
using namespace std;

int f[MAX_N][MAX_N];
long long dp[MAX_N];

int main()
{
	int n, m;//ÐÐ¼°ÁÐ
	cin >> n >> m;
	fill(&dp[0], &dp[0] +  MAX_N, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)cin >> f[i][j];
	for (int i = n - 1; i >= 1; i--)
		for (int j = 1; j <= m; j++)
		{
			if (f[i][j] == 0)continue;
			f[i][j] += f[i + 1][j];
		}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		deque<int> s;
		f[i][m + 1] = INT_MIN;
		s.push_back(m + 1);
		for (int j = m; j >= 1; j--)
		{
			for (;f[i][s.back()] >= f[i][j];s.pop_back());
			dp[j] = dp[s.back()] + f[i][j] * (s.back() - j);
			s.push_back(j);
			ans += dp[j];
		}
	}
	cout << ans%100007;
	return 0;
}