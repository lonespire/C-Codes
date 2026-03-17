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




int dp[MAX_V] = { 0 };

int main()
{
	int v, n;
	cin >> v >> n;
	for (int i = 1, Weight, Value, Quantity; i <= n; i++)
	{
		cin >> Weight >> Value >> Quantity;
		for (int k = 1; k <= Quantity; k++)
		{
			for (int j = v; j >= Weight; j--)
			{
				//1
				dp[j] = max(dp[j], dp[j - Weight] + Value);
			}
		}
	}
	cout << dp[v];
	return 0;
}