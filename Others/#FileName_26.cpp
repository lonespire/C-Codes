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
int n, ans[15];
void print_ans(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (i - 1) cout << "+";
		cout << ans[i];
		
	}
	cout << endl;
}

void dfs(int cnt, int residue, int last)
{
	if (cnt != 0) ans[cnt] = last;
	if (residue == 0)
	{
		if (cnt >= 2) print_ans(cnt);
		return;
	}
	for (int i = last; i<=n; i++)
	{
		if (residue - i < i && residue - i != 0)continue;
		dfs(cnt + 1, residue - i, i);
	}
	return;
}




int main()
{
	cin >> n;
	dfs(0, n, 1);

	return 0;
}