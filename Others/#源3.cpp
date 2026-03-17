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
#define MAX_N 405
#define MAX_K 10
using namespace std;

int board[MAX_N][MAX_N];
int to_ward[8][2] = { {1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1} };
void dfs(int n, int m, int x, int y, int cnt)
{
	if (cnt > board[x][y]) return;
	board[x][y] = cnt;
	for (int i = 0; i < 8; i++)
	{
		int x1 = x + to_ward[i][0], y1 = y + to_ward[i][1];
		if (x1<1 || x1>n || y1<1 || y1>m) continue;
		dfs(n, m, x1, y1, cnt + 1);
	}
	return;
}


int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	fill(&board[0][0], &board[0][0] + MAX_N * MAX_N, INT_MAX);
	board[x][y] = 0;
	dfs(n, m, x, y, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << (board[i][j] == INT_MAX ? -1 : board[i][j]) << " ";
		}
		cout << endl;
	}

	return 0;
}