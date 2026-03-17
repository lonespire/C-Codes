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
#define MAX_N 300005
#define MAX_K 10
using namespace std;



int num[MAX_N] = { 0 };


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		num[i] += num[i - 1];
	}
	deque<int> d;
	d.push_back(0);
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, num[i] - num[d.front()]);
		while (!d.empty() && num[d.back()] > num[i]) d.pop_back();
		d.push_back(i);
		if (i - d.front() >= m) d.pop_front();

	}
	cout << ans;
	return 0;
}