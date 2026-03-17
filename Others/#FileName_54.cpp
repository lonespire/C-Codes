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
#define CRT_SECURE_NO_WARNINGS
#define MAX_N 1000
#define MAX_K 10
#define lowbit(x) (x&-x)
using namespace std;
typedef long long ll;
int n;
vector<int> num, c;


void add(int i, int temp)
{
	while (i <= n)
	{
		c[i] += temp;
		i += lowbit(i);
	}
	return;
}
int query(int i)
{
	int sum = 0;
	while (i)
	{
		sum += c[i];
		i -= lowbit(i);
	}
	return sum;
}
int binary_search_01(int temp)
{
	int l = 1, r = n;
	while (l < r)
	{
		int mid = ((l + r) >> 1);
		if (query(mid) >= temp)
		{
			r = mid;
		}
		else if (query(mid) < temp)
		{
			l = mid + 1;
		}
	}
	return l;
}



int main()
{
	::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	num.resize(n+1);
	c.resize(n + 1, 0);
	num[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		if(i!=1) cin >> num[i];
		add(i, 1);
	}
	for (int i = n; i >= 1; i--)
	{
		int ind = binary_search_01(num[i] + 1);
		add(ind, -1);
		num[i] = ind;
	}
	for (int i = 1; i <= n; i++)cout << num[i] << '\n';
	return 0;
}
