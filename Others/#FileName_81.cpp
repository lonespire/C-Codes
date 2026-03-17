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
#define MAX_N 1000
#define MAX_K 10
using namespace std;

typedef long long ll;
ll a, b, k;




int main()
{
	cin >> a >> b >> k;
	ll ans = 0;

	while (1)
	{
		if (a == 0 || k == 0||k==1)
		{
			cout << b-a;
			return 0;
		}
		if (a * k <= b)
		{
			ans++;
			ans += b % k;
			b /= k;
		}
		else
		{
			ans += b - a;
			break;
		}
		
	}
	cout << ans;
	return 0;
}