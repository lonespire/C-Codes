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

int fx, fy;
bool nm_map[6][6];
int to_ward[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int dfs(int n, int m, int x, int y)
{
	if (x == fx && y == fy) return 1;
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		int x1 = x + to_ward[i][0], y1 = y + to_ward[i][1];
		if (x1<1 || y1<1 || x1>n || y1>m || nm_map[x1][y1]) continue;
		nm_map[x1][y1] = 1;
		ans+=dfs(n, m, x1, y1);
		nm_map[x1][y1] = 0;
	}
	return ans;
}

int main()
{
	int n, m, t, x, y;
	cin >> n >> m >> t >> x >> y >> fx >> fy;
	fill(&nm_map[0][0], &nm_map[0][0] + 6 * 6, 0);
	for (int i = 1; i <= t; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		nm_map[temp1][temp2] = 1;
	}
	nm_map[x][y] = 1;
	cout<<dfs(n,m,x,y);

	return 0;
}