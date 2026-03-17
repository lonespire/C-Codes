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
#define MAX_N 5005
#define MAX_K 10
using namespace std;




int k, v, n;
deque<int> dp[MAX_N];


int main()
{
	cin >> k >> v >> n;
	for (int i = 0; i <= v; i++)dp[i].resize(k,INT_MIN);
	dp[0][0] = 0;
	for (int i = 1,V,W; i <= n; i++)
	{
		cin >> V >> W;
		for (int j = v; j >= V; j--)
		{
			deque<int> temp;
			int x = 0, y = 0;
			for (int l = 1; l <= k; l++)
			{
				if (dp[j][x] > dp[j - V][y] + W)
				{
					temp.push_back(dp[j][x++]);
				}
				else
				{
					temp.push_back(dp[j-V][y++]+W);
				}

			}
			for (int z = 0; z < k; z++)dp[j][z] = temp[z];
		}
	}
	int ans = 0;
	for (int i = 0; i < k; i++)ans += dp[v][i];
	cout << ans;

	return 0;
}