
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

int n, ans[105][105], toward[8][2] = { {1,1},{1,-1},{-1,1},{-1,-1},{1,0},{0,1},{-1,0},{0,-1} },flag=1;
string a = "yizhong";
char word[105][105];
void find_a(int i, int j, int cnt,int way)
{
	if (cnt == 6)
	{
		flag = 0;
		ans[i][j]++;
		return;
	}
	ans[i][j]++;
	if (word[i][j] == a[cnt]&& i + toward[way][0]<=n&& i + toward[way][0]>0&& j + toward[way][1]<=n&& j + toward[way][1]>0)
	{
		find_a(i + toward[way][0], j + toward[way][1], cnt + 1, way);
	}
	if (flag) ans[i][j]--;
	return;
}



int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) cin >> word[i][j];
	fill(&ans[0][0], &ans[0][0] + 105 * 105, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int t = 0; t < 8; t++)
			{
				flag = 1;
				find_a(i, j, 0, t);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (ans[i][j]) cout << word[i][j];
			else cout << "*";
		}
		cout << endl;
	}
	return 0;
}