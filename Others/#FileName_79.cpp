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
#define MAX_N 1000005
#define MAX_K 10
using namespace std;
typedef long long ll;


ll x[MAX_N], p[MAX_N], c[MAX_N], t[MAX_N];//t---x*p前缀和
deque<ll> d;//存放节点编号
ll dp[MAX_N];
double sclope(int j, int k)//放入节点编号
{
	return (1.0 * (dp[j] - dp[k] + t[j] - t[k])) / (1.0* (p[j] - p[k]));
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> p[i] >> c[i];
		t[i] = p[i] * x[i] + t[i - 1];
		p[i] += p[i - 1];
	}
	d.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		while (d.size() >= 2 && sclope(d.front(), d[1]) <= x[i])d.pop_front();
		dp[i] = dp[d.front()] + t[d.front()] - x[i] * p[d.front()] + x[i] * p[i] - t[i] + c[i];
		while (d.size() >= 2 && (dp[d.back()] - dp[d[d.size() - 2]] + t[d.back()] - t[d[d.size() - 2]]) * (p[i] - p[d.back()]) >= (dp[i] - dp[d.back()] + t[i] - t[d.back()]) * (p[d.back()] - p[d[d.size() - 2]]))d.pop_back();
		d.push_back(i);
	}
	int ans = dp[n];
	for (int i = n - 1; p[i] == p[i + 1]; i--)ans = dp[i];
	cout << ans;
	
	return 0;
}
