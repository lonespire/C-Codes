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
#include <unordered_map>
#define MAX_N 20
#define MAX_K 10
using namespace std;

unordered_map<int, int> bitmask;
struct Node
{
	double x, y;
} tree[MAX_N];

int n;
double ans = INT_MAX, dp[70000][MAX_N];
double dis(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
void dfs(int cur, int t1, double sum)
{

	if (dp[t1][cur] <= sum || sum >= ans)
		return;
	dp[t1][cur] = sum;
	if (t1 == 0)
	{
		ans = min(ans, sum);
		return;
	}
	for (int t = t1; t != 0; t -= (t & -t))
	{
		int next = bitmask[t & -t];
		dfs(next, t1 ^ (1 << next), sum + dis(tree[cur].x, tree[cur].y, tree[next].x, tree[next].y));
	}
	return;
}

int main()
{

	cin >> n;
	fill(&dp[0][0], &dp[0][0] + 70000 * MAX_N, INT_MAX);
	for (int i = 1; i <= n; i++)
		cin >> tree[i].x >> tree[i].y;
	for (int i = 0; i <= n + 1; i++)
		bitmask[(1 << i)] = i;
	tree[0].x = 0;
	tree[0].y = 0;
	dfs(0, (1 << n + 1) - 2, 0);
	printf("%.2lf\n", ans);
	// for (int i = 1; i <= n; i++) cout<< tree[i].x << tree[i].y;
	return 0;
}