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


bool visual[9];
int num[9];
void nb(int cur, int cnt, int n)
{
	visual[cur] = 1;
	num[cnt] = cur;
	if (cnt == n)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << num[i];
			if (i != n)cout << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visual[i])continue;
		nb(i, cnt + 1, n);
		visual[i] = 0;
	}
}



int main()
{
	fill(visual, visual + 9, 0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		nb(i, 1, n);
		visual[i] = 0;
	}

	return 0;
}