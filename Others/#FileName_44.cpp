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
#define CRT_SECURE_NO_WARNINGS
#define MAX_N 1000
#define MAX_K 10
using namespace std;

typedef long long ll;
vector<int> num,dp;



int main()
{
	int n;
	cin >> n;
	num.resize(n+1);
	dp.resize(n+1,1);
	for (int i = 1; i <= n; i++)
	{
		cin>>num[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (num[i] <= num[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
