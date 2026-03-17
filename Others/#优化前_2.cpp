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
#include<cinttypes>
#define MAX_N 1000000
//#define MAX_K 10
using namespace std;


int dp[MAX_N] = { 0 };
int Number[MAX_N];

int main()
{
	int n;
	cin >> n;
	Number[0] = INT32_MIN;
	for (int i = 2; i <= n; i++)
	{
		cin >> Number[i];
		for (int j = 0; j <= i; j++)
		{
			if (Number[i] > Number[j])dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	int MAX = 0;
	for (int i = 1; i <= n; i++)
	{
		MAX = max(MAX, dp[i]);
	}

	cout << MAX;
	return 0;
}