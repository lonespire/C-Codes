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
#define MAX_N 100
#define MAX_K 10
using namespace std;
typedef long long ll;



ll Matix[MAX_N][MAX_N];




int main()
{
	fill(&Matix[0][0], &Matix[0][0] + MAX_N * MAX_N, 0);
	ll n, ans = INT_MIN;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> Matix[i][j];
			Matix[i][j] += Matix[i - 1][j] + Matix[i][j - 1] - Matix[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = i; k <= n; k++)
			{
				for (int l = j; l <= n; l++)
				{
					ans = max(ans, Matix[k][l] - Matix[i - 1][l] - Matix[k][j - 1] + Matix[i - 1][j - 1]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}