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
#include<unordered_map>
#define MAX_X 1000005
#define MAX_K 10
using namespace std;
typedef long long ll;
unordered_map<int, int > bitmask;
bool sushu[MAX_X * 20];
ll num[22];
vector<ll> d;	

void if_sushu(ll n)
{
	deque<ll> is;
	for (ll i = 2; i <= n; i++)
	{
		if (sushu[i]) is.push_back(i);
		for (auto j : is)
		{
			if (j * i > n)break;
			sushu[j * i] = 0;
			if (i % j == 0) break;

		}
	}
}
int dfs(int cnt,int t1, int k,ll sum,int cur)
{
	if (cnt >= k)
	{
		if (sushu[sum]) return 1;
		return 0;
	}
	int ans = 0;
	for (int t = t1; t != 0; t -= (-t & t))
	{
		int i = bitmask[-t & t];
		if (i < cur) continue;
		ans += dfs(cnt + 1, t1 ^ (1 << i), k, sum + num[i],i);
	}
	return ans;
}




int main()
{
	int n, k,t;
	cin >> n >> k;
	num[0] = 0;
	for (int i = 1; i <= n; i++)cin >> num[i];
	for (int i = 0; i <=  n+1; i++) bitmask[(1 << i)] = i;
	for (int i = 1; i <= MAX_X * k - 1; i++)sushu[i] = true;
	sushu[1] = false;
	if_sushu(MAX_X * 20-1);
	cout<<dfs(0, (1 << (n + 1)) - 2, k, 0,0)<<endl;
	//for (int i = 1; i <= MAX_X * 20 - 1; i++)if (sushu[i]) cout << i << " ";
	return 0;
}