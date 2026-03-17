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
#include <unordered_map>
#define MAX_K 10
using namespace std;

class Union_find
{
public:
	vector<int > fa;
	Union_find(int n) : fa(n) {
		for (int i = 0; i < n; i++) fa[i] = i;
	}
	int find(int x)
	{
		return fa[x] = (fa[x] == x ? x : find(fa[x]));
	}
	void merge(int x, int y)
	{
		if (find(x) == find(y))return;
		fa[find(x)] = find(y);
		return;
	}

};

struct Problem
{
	long long	i, j;
	int e;
};


int main()
{
	int problem_n;
	cin >> problem_n;
	for (int pn = 1; pn <= problem_n; pn++)
	{
		int n, cnt = 0,flag=1;
		cin >> n;
		vector<Problem> problem(n);
		unordered_map<long long, int> index;
		for (int i = 0; i < n; i++)
		{
			cin >> problem[i].i >> problem[i].j >> problem[i].e;
			if (!index.count(problem[i].i)) index[problem[i].i] = cnt++;
			if (!index.count(problem[i].j)) index[problem[i].j] = cnt++;
		}

		Union_find u(cnt+1);
		for (int i = 0; i < n; i++)
		{
			if (problem[i].e == 0)continue;
			u.merge(index[problem[i].i], index[problem[i].j]);
		}
		for (int i = 0; i < n; i++)
		{
			if (problem[i].e == 1)continue;
			if (u.find(index[problem[i].i]) == u.find(index[problem[i].j]))
			{
				flag = 0;
				break;
			}
		}
		if (flag) cout << "YES"<<endl;
		else cout << "NO"<<endl;
	}

	return 0;
}