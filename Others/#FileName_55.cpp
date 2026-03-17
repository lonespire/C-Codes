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
#define lowbit(ttt) (ttt&-ttt)
using namespace std;

vector<int> x, num, c, ans;
int n;


void add(int i,int val)
{
	while (i <= n)
	{
		c[i] += val;
		i += lowbit(i);
	}
	return;
}
int query(int i)
{
	if (i == 0) return 0;
	return c[i] + query(i - lowbit(i));
}
int binary_search_01(int target)
{
	int l = 1, r = n;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (query(mid) < target) l = mid + 1;
		else r = mid;
	}
	return l;
}
int main()
{
	::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	x.resize(n+1);
	num.resize(n+1);
	c.resize(n+1, 0);
	ans.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		cin >> num[i];
		add(i, 1);
	}
	for (int i = n; i >= 1; i--)
	{
		int ind = binary_search_01(x[i] + 1);
		ans[ind] = num[i];
		add(ind, -1);
	}
	for (int i=1;i<=n;i++)
	{
		if (i != 1) cout << " ";
		cout << ans[i];
	}
	return 0;
}
