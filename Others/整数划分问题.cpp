#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#define MAX_N 200
#define MAX_K 6
using namespace std;
int f[MAX_N][MAX_K] = {0};
int main()
{
	int n, k;
	cin >> n >> k;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i][1] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= min(i,k); j++)
		{
			f[i][j] = f[i - 1][j - 1] + f[i - j][j];
		}
	}
	cout << f[n][k];
	return 0;
}