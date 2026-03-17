#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <climits>
#define MAX_N 1000000
#define MAX_M 10000
using namespace std;


long long sum[MAX_N+5];
long long dp[MAX_N+5];
long long f(int i)
{
	return dp[i] + 1.0*sum[i]*sum[i];
}
double slope(int i, int j)
{
	return (1.0 * (f(i) - f(j))) / (1.0 * (sum[i] - sum[j]));
}

int main()
{
	int n, m;
	cin >> n >> m;
	fill(dp, dp + MAX_N, 0);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	deque<int> d;
	d.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		while (d.size() >= 2 && slope(d.front(), d[1]) <= 2 * sum[i])d.pop_front();
		dp[i] = dp[d.front()] + (sum[i] - sum[d.front()])*(sum[i] - sum[d.front()])*1.0 + m;
		while (d.size() >= 2 && slope(d[d.size()-2], d.back()) > slope(d.back(), i))d.pop_back();
		d.push_back(i);
	}
	cout << dp[n];
	return 0;
}