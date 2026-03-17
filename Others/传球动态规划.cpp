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
#define MAX_N 30
#define MAX_M 30
using namespace std;




int f[MAX_N+5][MAX_N+5] = { 0 };

int main()
{
	int n, m;
	cin >> n >> m;
	f[0][1] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 2; j <=n-1; j++)
		{
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
			
		}
		f[i][1] = f[i - 1][n] + f[i - 1][2];
		f[i][n] = f[i - 1][n - 1] + f[i - 1][1];
	}
	cout << f[m][1]<<endl<<1+1;

	return 0;
}