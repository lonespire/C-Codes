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
#define MAX_N 1000
#define MAX_K 10
using namespace std;




int dp[MAX_N][MAX_N] = { 0 };

int main()
{
	string a = " ", temp;
	cin >> temp;
	a += temp;
	for (int l = 0; l < a.size() - 1; l++)
	{
		for (int i = 1; i <= a.size() - l - 1; i++)
		{
			int j = i + l;
			if (a[i] == a[j] && dp[i + 1][j - 1] == 0)continue;
			dp[i][j] = l;
			for (int k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
			}
		}
	}
	cout << dp[1][a.size() - 1] << endl;
	return 0;
}