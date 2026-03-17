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
#define MAX_N 205
#define MAX_K 10
using namespace std;



int k[MAX_N];
int dis[MAX_N];

void dfs(int cnt, int cur, int n)
{
	if (cnt >= dis[cur])return;
	dis[cur] = cnt;
	if (cur + k[cur] <= n)dfs(cnt + 1, cur + k[cur], n);
	if (cur - k[cur] >= 1)dfs(cnt + 1, cur - k[cur], n);
}

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	fill(dis, dis + MAX_N, INT_MAX);
	for (int i = 1; i <= n; i++)cin >> k[i];
	dfs(0, a, n);
	cout << (dis[b] == INT_MAX ? -1 : dis[b]);

	return 0;
}