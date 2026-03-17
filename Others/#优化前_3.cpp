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
#include<limits>
#define MAX_N 35
#define MAX_M 100000
using namespace std;



int dp[MAX_N][MAX_M] = { 0 };


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)dp[1][i] = i;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = j;
			for (int k = 1; k <= j; k++)
			{
				dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]));
			};
			dp[i][j]++;
		}
	}
	cout << dp[n][m];
	return 0;
}