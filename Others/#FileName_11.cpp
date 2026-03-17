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
#define MAX_K 1000
using namespace std;



long long dp[MAX_N][MAX_K] = { 0 };


int main()
{
	long long n, m;
	cin >> n >> m;
	if (n == 1)
	{
		cout << m;
		return 0;
	}
	for (int i = 1; i <= MAX_K; i++)dp[1][i] = i;
	for (int i = 2; i <= n; i++)
	{
		for (int j=1; j <= MAX_K; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
			if (dp[i][j] >= m)
			{
				break;
			}
		}
	}
	for (int i = 1; 1; i++)
	{
		if (dp[n][i] >= m)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}