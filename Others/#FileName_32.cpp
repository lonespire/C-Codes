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
	vector<int> fa, value;
	Union_find(int n) :fa(n), value(n)
	{
		for (int i = 0; i < n; i++)
		{
			fa[i] = i;
			value[i] = 0;
		}
	}
	int find(int x)
	{
		if (fa[x] == x) return x;
		int root = find(fa[x]);
		value[x] = (value[x] + value[fa[x]] + 3) % 3;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y)
	{
		int fx = find(x), fy = find(y);
		if (fx == fy) return;
		value[x] = (value[y] - value[x] + 4) % 3;
		fa[fx] = fy;
		return;
	}

};


int main()
{
	int n, m;
	cin >> n >> m;
	Union_find u(n + 1);
	for (int i = 1; i <= m; i++)
	{
		int temp, x, y;
		cin >> temp >> x >> y;
		if (temp == 1)
		{
			u.merge(x, y);
		}
		else if (temp == 2)
		{
			if (u.find(x) != u.find(y))
			{
				cout << "Unknown" << endl;
				continue;
			}
			int val_x = (u.value[x] - u.value[y] + 3) % 3;
			switch (val_x)
			{
			case 0:cout << "Tie" << endl; break;
			case 1:cout << "Win" << endl; break;
			case 2:cout << "Loss" << endl; break;
			default:
				break;
			}
		}
	}


	return 0;
}