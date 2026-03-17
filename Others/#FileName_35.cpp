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

class Union_find
{
public:
	vector<int > fa, value;
	Union_find(int n) : fa(n), value(n) {
		for (int i = 0; i < n; i++)
		{
			fa
				[i] = i;
			value
				[i] = 0;
		}
	}
	int find(int x) {
		if (fa[x] != x) {
			int root = find(fa[x]);
			value
				[x] = (value[x] + value[fa[x]]) % 2;
			fa
				[x] = root;
		}
		return fa[x];
	}
	void merge(int a, int b, int t) {
		int aa = find(a), bb = find(b);
		if (aa == bb) return;
		value
			[aa] = (t - value[a] + value[b] + 2) % 2;
		fa
			[aa] = bb;
		return;
	}

};
struct Anger
{
	int x, y, c;
};
bool cmp(Anger a, Anger b)
{
	return a.c > b.c;
}


int main()
{
	int n, m;
	cin
		>> n >> m;
	Union_find u(n + 1);
	vector<Anger> anger(m);
	for (int i = 0; i < m; i++) cin >> anger[i].x >> anger[i].y >> anger[i].c;
	sort(anger.begin(), anger.end(), cmp);
	for (int i = 0; i < m; i++)
	{
		if (u.find(anger[i].x) != u.find(anger[i].y)) u.merge(anger[i].x, anger[i].y, 1);
		else
		{
			if ((u.value[anger[i].x] + u.value[anger[i].y] + 2) % 2 == 0)
			{
				cout
					<< anger[i].c;
				return 0;
			}
		}
	}
	cout
		<< 0;
	return 0;
}