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
#define MAX_N 2005
#define MAX_K 80
using namespace std;

int dp[MAX_N];
string Words[MAX_N];
bool is_pre(int j, int i)
{
	if (Words[j].size() > Words[i].size())return 0;
	for (int l = 0; l < Words[j].size();l++)
	{
		if (Words[j][l] != Words[i][l])return 0;
	}
	return 1;
}



int main()
{
	int n,ans=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> Words[i];
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (is_pre(j, i))dp[i] = max(dp[j] + 1, dp[i]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}