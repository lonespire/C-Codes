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
int to_ward[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
struct Node
{
	Node(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
	int x, y, cnt;
};
void bfs(int n, int m, int x, int y, int cnt)
{
	deque<Node> d;
	d.push_back(Node(x, y, cnt));
	board[x][y] = 0;
	while (!d.empty())
	{
		Node now = d.front();
		d.pop_front();
		for (int i = 0; i < 8; i++)
		{
			int x1 = now.x + to_ward[i][0], y1 = now.y + to_ward[i][1];
			if (x1 < 1 || y1 < 1 || x1 > n || y1 > m || board[x1][y1] != -1)
				continue;
			d.push_back(Node(x1, y1, now.cnt + 1));
			board[x1][y1] = now.cnt + 1;
		}
	}
	return;
}

int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	fill(&board[0][0], &board[0][0] + MAX_N * MAX_N, -1);
	board[x][y] = 0;
	bfs(n, m, x, y, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}