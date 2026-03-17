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

vector<ll> num, c1, c2;//c2Ϊi*x{i}

void add(ll i, vector<ll> &a,ll c)
{
	while (i <= a.size()-1)
	{
		a[i] += c;
		i += lowbit(i);
	}
	return;
}
ll query(ll i, vector<ll>& a)
{
	ll sum = 0;
	while (i)
	{
		sum += a[i];
		i -= lowbit(i);
	}
	return sum;
}
ll getsum(int k)
{
	return query(k, c1) * (k + 1) - query(k, c2);
}
int main()
{
	::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, m;
	cin >> n >> m;
	num.resize(n + 1);
	num[0] = 0;
	c1.resize(n + 1, 0);
	c2.resize(n + 1, 0);
	for (ll i = 1; i <= n; i++)
	{
		cin >> num[i];
		add(i, c1, num[i] - num[i - 1]);
		add(i, c2, (num[i] - num[i - 1])*i);
	}
	while (m--)
	{
		char op;
		cin >> op;
		if (op == 'C')
		{
			ll a, b;
			ll c;
			cin >> a >> b >> c;
			add(a, c1, c);
			add(a, c2, c * a);
			add(b + 1, c1, -c);
			add(b + 1, c2, -c * (b + 1));
		}
		else
		{
			ll a, b;
			cin >> a >> b;/*
			ll k = b - a + 1;*/
			cout << getsum(b)-getsum(a-1) << '\n';
		}
	}
	return 0;
}
