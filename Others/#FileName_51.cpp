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
#define mod 998244353
using namespace std;
typedef long long ll;





int main()
{
	::ios::sync_with_stdio(false), cin.tie(nullptr);
	ll a, b, ans=1;
	cin >> a >> b;
	while (b != 0)
	{
		a %= mod;
		if ((b & 1) == 1)ans *= a;
		a *= a;
		ans %= mod;
		a %= mod;
		b=b >> 1;
	}
	cout << ans;
	return 0;
}
