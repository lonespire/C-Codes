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
using namespace std;






int main()
{
	::ios::sync_with_stdio(false), cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ans1 = 0, ans2 = 0, switch0=0, switch1=0;
		while (n--)
		{
			int temp;
			cin >> temp;
			if (temp == 0)switch0++;
			else switch1++;
		}
		ans2 = min(switch0, switch1);
		if (switch1 %2 == 1) ans1 ++;
		cout << ans1 << " " << ans2 << '\n';
	}

	return 0;
}
