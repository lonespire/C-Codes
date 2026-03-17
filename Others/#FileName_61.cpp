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
#include <unordered_map>
#define CRT_SECURE_NO_WARNINGS
#define MAX_N 1000
#define MAX_K 10
using namespace std;






int main()
{
	int n;
	cin >> n;
	pair<int, int> maxn;
	unordered_map<int, int> num, cnt;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		num[temp] = i;
		cnt[temp]++;
	}
	int MAXN = -1, MAXI = -1;
	for (auto i : cnt)
	{
		if (i.second == 1)
		{
			if (i.first > MAXN)
			{
				MAXN = i.first;
				MAXI = num[i.first];
			}
		}
	}
	
	cout << MAXI;
	return 0;
}
