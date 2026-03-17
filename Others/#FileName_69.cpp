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
#define MAX_N 1000
using namespace std;



int dp[MAX_N][MAX_N], ans[MAX_N][MAX_N];
int m[MAX_N], r[MAX_N], t[MAX_N];


int main()
{
	int n,M,R;
	fill(&dp[0][0], &dp[0][0] + MAX_N * MAX_N, 0);
	fill(&ans[0][0], &ans[0][0] + MAX_N * MAX_N,0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i] >> r[i] >> t[i];
	}
	cin >> M >> R;
	ans[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = M; j >= m[i]; j--) {
			for (int k = R; k >= r[i]; k--)
			{
				if (dp[j - m[i]][k - r[i]] + 1 > dp[j][k])
				{
					dp[j][k] = dp[j - m[i]][k - r[i]] + 1;
					ans[j][k] = ans[j - m[i]][k - r[i]] + t[i];

				}
				else if (dp[j - m[i]][k - r[i]] + 1 == dp[j][k])ans[j][k] = min(ans[j][k], ans[j - m[i]][k - r[i]] + t[i]);

			}
		}
	}
	
	cout << ans[M][R];
	return 0;
}