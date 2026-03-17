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
#define MAX_H 405
#define MAX_K 505
using namespace std;


int  dp[MAX_H][MAX_H];



int main()
{
	int H, T, n,ans=0;
	cin >> H >> T >> n;
	for (int i = 1,h,t,k; i <= n; i++)
	{
		cin >> h >> t >> k;
		for (int j = H; j >= h; j--)
		{
			for (int l = T; l >= t; l--)
			{
				dp[j][l] = max(dp[j][l], dp[j - h][l - t] + k);
				ans = max(ans, dp[j][l]);
			}
		}
	}
	cout << ans;

	return 0;
}