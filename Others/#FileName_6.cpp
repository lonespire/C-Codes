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
#define MAX_N 500005
#define MAX_K 10
using namespace std;




int dp[MAX_N] = { 0 };
string a = " ";
int n;
vector<int> Legal[MAX_N];
void is_legal(int i, int j)
{
	while (i>=1&&j<=n&&a[i]==a[j])
	{
		Legal[j].push_back(i-1);
		i--;
		j++;
	}
	return ;
}
int main()
{
	string temp;
	cin >> temp;
	a += temp;
	n = a.size()-1;
	for (int i = 1; i <= n; i++)
	{
		is_legal(i, i);
		is_legal(i, i + 1);
	}
	dp[0] = -1;
	for (int i = 1; i <=n; i++)
	{
		dp[i] = i;
		for (auto j : Legal[i])
		{
			dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	cout << dp[n] << endl;
	return 0;
}