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
#define MAX_N 105
#define MAX_K 10
using namespace std;
typedef long long ll;
ll dp[MAX_N] = { 0 };
int Number[MAX_N];



int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> Number[i];
		dp[i] = Number[i];
	}
	dp[2] = max(abs(Number[1] - Number[2]) * 2,Number[1]+Number[2]);
	for (int i = 3; i <= n; i++)
	{
		dp[i] += dp[i - 1];
		for (int j = 0; j < i-1; j++)
		{
			//if (j + 1 == i)continue;
			dp[i] = max(dp[i], dp[j] + abs(Number[i] - Number[j + 1]) * (i - j));
		}
	}
	cout << dp[n]<<endl;
	for (int i = 1; i <= n; i++)
	{
		cout<< dp[i]<<" ";
	}
	return 0;
}