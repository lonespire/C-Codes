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
#define MAX_N 10005
#define MAX_K 10
using namespace std;


long long Triangle[MAX_N][MAX_N];
long long f[MAX_N][MAX_N] = {0};

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> Triangle[i][j];
		}
	}
	f[1][1]=Triangle[1][1];
	for (int i = 2; i <= n; i++)
	{
		f[i][1] = f[i - 1][1] + Triangle[i][1];
		for (int j = 2; j <= i; j++)
		{
			f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + Triangle[i][j];
		}
	}
	long long MAX = 0;
	for (int i = 1; i <= n; i++)
	{
		if (MAX < f[n][i])MAX = f[n][i];
	}
	cout << MAX;
	return 0;
}