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


int dp[41][41][41] = { 0 };
int val[MAX_N];
int cnt[5] = { 0 };

int main()
{
	int n, m;
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
	for (int i = 0; i <= cnt[1]; i++)
	{
		for (int j = 0; j <= cnt[2]; j++)
		{
			for (int k = 0; k <= cnt[3]; k++)
			{
				for (int l = 0; l <= cnt[4]; l++)
				{
					int cur =1+ i + 2 * j + 3 * k + 4 * l;
					int ans = dp[j][k][l];
					if (j)ans = max(dp[j - 1][k][l] , ans);
					if (k)ans = max(dp[j][k - 1][l] , ans);
					if (l)ans = max(dp[j][k][l - 1] , ans);
					dp[j][k][l] = ans + val[cur];
				}
			}
		}
	}
	cout << dp[cnt[2]][cnt[3]][cnt[4]];
	//cout <<sum;
	return 0;
}