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
#define MAX_N 1005
#define MAX_K 10
using namespace std;




int dp[MAX_N][MAX_N] = { 0 };

int main()
{
	string a=" ", b=" ",temp1,temp2;
	cin >>temp1>>temp2;
	a += temp1;
	b += temp2;
	for (int i = 1; i <= a.size()-1; i++)
	{
		for (int j = 1; j <= b.size()-1; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i] == b[j])dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	cout << dp[a.size()-1][b.size()-1]<<endl;
	return 0;
}