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
#include <climits>
using namespace std;

#define MAX_N 100005
#define MAX_K 10


int DIS(int x1,int  y1,int x2,int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int x1, y1, x2, y2;
int x[MAX_N], y[MAX_N], ind[MAX_N], dis[MAX_N];
bool cmp(int i, int j)
{
	return DIS(x[i], y[i], x1, y1) < DIS(x[j], y[j], x1, y1);
}



int main()
{
	int n;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		ind[i] = i;
	}
	sort(ind + 1, ind + 1 + n, cmp);
	for (int i = n; i >= 1; i--)dis[i] = max(DIS(x[ind[i]], y[ind[i]], x2, y2), dis[i + 1]);
	int ans = dis[1];
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, DIS(x[ind[i]], y[ind[i]], x1, y1) + dis[i + 1]);
	}
	cout<<ans;
	return 0;
}