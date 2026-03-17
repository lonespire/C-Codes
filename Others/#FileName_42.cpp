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
#define lowbit(x) (x&-x)
#define MAX_N 1000
#define MAX_K 10
using namespace std;

typedef long long ll;
vector<ll> num, tree, l, r;
void add(ll ind, ll c)
{
	while (ind <= tree.size() - 1)
	{
		tree[ind] += c;
		ind += lowbit(ind);
	}
	return;
}
ll query(ll ind)
{
	ll sum = 0;
	while (ind)
	{
		sum += tree[ind];
		ind -= lowbit(ind);
	}
	return sum;
}
int main()
{
	ll n;
	scanf("%lld", &n);
	num.resize(n + 1);
	tree.resize(n + 1, 0);
	l.resize(n + 1);
	r.resize(n + 1);
	for (ll i = 1; i <= n; i++)cin >> num[i];
	for (ll i = 1; i <= n; i++)
	{
		l[i] = query(num[i]);
		add(num[i], 1);
	}
	fill(tree.begin(), tree.end(), 0);
	for (ll i = n; i >= 1; i--)
	{
		r[i] = query(num[i]);
		add(num[i], 1);
	}
	ll ans1 = 0, ans2 = 0;
	for (ll i = 1; i <= n; i++)
	{
		ans1 += l[i] * r[i];
		ans2 += (i - 1 - l[i]) * (n - i - r[i]);
	}
	printf("%lld %lld", ans2, ans1);
	return 0;
}
