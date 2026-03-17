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
#define MAX_N 100005
#define MAX_K 10
using namespace std;

typedef long long ll;

ll dp[4][MAX_N], number[MAX_N];


int main()
{
	int n;
	cin >> n;
	fill(&dp[0][0], &dp[0][0] + 4 * MAX_N, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> number[i];
		dp[1][i] = 1;
	}

	for (int i = 1; i <= 2; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			for (int k =i; k < j; k++)
			{
				if (number[k] < number[j])dp[i + 1][j] += dp[i][k];

			}
			//cout << dp[i+1][j] << " ";
		}
		//cout << endl;
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++)sum += dp[3][i];
	cout << sum;
	return 0;
}