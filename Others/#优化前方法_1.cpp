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
#define MAX_N 352
#define MAX_M 122
using namespace std;


int dp[41][41][41][41] = { 0 };
int val[MAX_N];
int cnt[5] = { 0 };

int main()
{
	int n, m, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}
	for (int i = 1; i <= m; i++)
	{
		int temp;
		cin >> temp;
		cnt[temp]++;
	}
	dp[0][0][0][0] = val[1];
	for (int i = 0; i <= cnt[1]; i++)
	{
		for (int j = 0; j <= cnt[2]; j++)
		{
			for (int k = 0; k <= cnt[3]; k++)
			{
				for (int l = 0; l <= cnt[4]; l++)
				{
					int cur = 1 + i + 2 * j + 3 * k + 4 * l;
					int ans = dp[i][j][k][l];
					if (i)ans = max(dp[i - 1][j][k][l] + val[cur], ans);
					if (j)ans = max(dp[i][j - 1][k][l] + val[cur], ans);
					if (k)ans = max(dp[i][j][k - 1][l] + val[cur], ans);
					if (l)ans = max(dp[i][j][k][l - 1] + val[cur], ans);
					dp[i][j][k][l] = ans;
					if (cur == n)sum = max(sum, ans);
				}
			}
		}
	}
	cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
	//cout <<sum;
	return 0;
}