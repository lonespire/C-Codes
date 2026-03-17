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
#define MAX_N 1005
#define MAX_K 10
using namespace std;



deque<pair<double, double>> section;//第一次使用pair
int x[MAX_N], y[MAX_N];
int main()
{
	int n, d,ans=0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		if (y[i] > d)
		{
			cout << -1;
			return 0;
		}
		section.push_back(make_pair(x[i] + sqrt(d * d - y[i] * y[i]), x[i] - sqrt(d * d - y[i] * y[i])));
	}
	sort(section.begin(), section.end());
	double cur = section.front().first;
	section.pop_front();
	ans++;
	while (!section.empty())
	{
		if (cur >= section.front().second)
		{
			section.pop_front();
		}
		else
		{
			cur = section.front().first;
			section.pop_front();
			ans++;
		}
	}
	cout << ans;
	return 0;
}