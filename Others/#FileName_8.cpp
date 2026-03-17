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
#include<limits>
#define MAX_N 1000000
//#define MAX_K 10
using namespace std;


int dp[MAX_N+5] = { 0 };
int len[MAX_N+5];
int Binary_Search(int ans, int Number)
{
	int head = 0, tail = ans, mid;

	while (head < tail)
	{
		mid = (head + tail + 1) >> 1;
		if (len[mid] < Number)head = mid;
		else tail = mid-1;
	}
	return head;
}
int main()
{
	int n,ans=0;
	cin >> n;
	len[0] = INT_MIN;
	for (int i = 1; i < MAX_N; i++)len[i] = INT_MAX;
	for (int i = 1, Number; i <= n; i++)
	{
		cin >> Number;
		dp[i] = Binary_Search(ans, Number)+1;
		len[dp[i]] = min(len[dp[i]], Number);
		ans = max(ans, dp[i]);
		
	}
	

	cout << ans;
	return 0;
}