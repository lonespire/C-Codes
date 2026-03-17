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
#define MAX_V 10005
#define MAX_N 105
#define MAX_W 1000005
using namespace std;




int dp[MAX_N][MAX_V] = { 0 };
int Weight[MAX_N];
int Value[MAX_N];

int main()
{
	int v, n;
	cin >> v >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> Weight[i];
		cin >> Value[i];
	}
	//为什么物品数量在外面
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j < Weight[i])continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j - Weight[i]] + Value[i]);
		}
	}
	cout << dp[n][v];
	return 0;
}