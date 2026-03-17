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
long long f[MAX_N][MAX_N] = { 0 };

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
	for (int i = 1; i <= n; i++)
	{
		f[n][i] = Triangle[n][i];
	}
	for (int i = n-1; i>=1 ; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + Triangle[i][j];
		}
	}
	
	cout << f[1][1];
	return 0;
}