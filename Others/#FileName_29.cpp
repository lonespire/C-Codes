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
#define MAX_N 100005
#define MAX_K 10
using namespace std;
typedef long long ll;

ll length[MAX_N] = { 0 };



int main()
{
	ll n,ans=0;
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		cin >> length[i];
	}
	deque<ll> d;
	d.push_back(0);
	for (ll i = 1; i <= n; i++)
	{
		while (!d.empty() && length[d.back()] > length[i])
		{
			ll temp = d.back();
			d.pop_back();
			ans = max((i - 1 - d.back()) * length[temp], ans);
		}
		d.push_back(i);
	}
	cout << ans;
	return 0;
}