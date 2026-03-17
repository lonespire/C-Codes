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
#define lowbit(x) (x&-x)
using namespace std;
typedef long long ll;
int n;
vector<ll> c;

void add(int i, ll val)
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

int main()
{
	::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	c.resize(1 + n, 0);
	ll temp1=0, temp2;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp2;
		if(temp2 - temp1>0) add(i, temp2 - temp1);
		temp1 = temp2;
	}
	cout << query(n);
	return 0;
}
