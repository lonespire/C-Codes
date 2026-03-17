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


typedef
struct Tree {
	int father;
	int c;
};
deque<pair<int, Tree>> d;
bool cmp(pair<int, Tree> a, pair<int, Tree> b)
{
	if(a.second.c != b.second.c)return a.second.c > b.second.c;
	return a.first < b.first;
}
bool used[MAX_N];
int main()
{
	fill(used, used + MAX_N, 0);
	int n, R, ans = 0, time = 0;
	cin >> n >> R;
	d.resize(n);
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		d[i - 1].second.c = temp;
		d[i-1].first = i;
	}
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		d[y - 1].second.father=x;
	}
	sort(d.begin(), d.end(), cmp);
	time = 1;
	ans = time * d[R].second.c;
	used[R] = 1;
	while (time != n)
	{
		for (int i=0;i<n;i++)
		{
			if (used[d[i].second.father] == 1&&used[d[i].first]==0)
			{
				time++;
				ans += time * d[i].second.c;
				used[d[i].first] = 1;
				cout << d[i].first << endl;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}