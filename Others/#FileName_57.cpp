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
using namespace std;

int binary_search_01(vector<int> num, int target)
{
	int l = 0, r = num.size() - 1;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (target <= num[mid])
		{
			r = mid;
		}
		else if (target > num[mid])
		{
			l = mid + 1;
		}
	}
	if (num[l] == target)
		return l;
	return l + 10;
}
int binary_search_10(vector<int> num, int target)
{
	int l = 0, r = num.size() - 1;
	while (l < r)
	{
		int mid = ((l + r + 1) >> 1);
		if (num[mid] > target)
		{
			r = mid - 1;
		}
		else if (num[mid] <= target)
		{
			l = mid;
		}
	}
	if (num[l] == target)
		return l;
	return l + 10;
}

int main()
{
	::ios::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int t;
	cin >> t;
	cout << binary_search_10(num, t);

	return 0;
}
