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
#define MAX_N 500005
#define MAX_K 10
using namespace std;


int a[MAX_N], b[MAX_N];



int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	deque<int> d1, d2;
	for (int i = 1; i <= n; i++)
	{
		while (!d1.empty() && !d2.empty() && (a[d1.back()] > a[i] || b[d2.back()] > b[i]))
		{
			if (a[d1.back()] > a[i]) d1.pop_back();
			if (b[d2.back()] > b[i])d2.pop_back();
		}

		d1.push_back(i);
		d2.push_back(i);
		if (d1.size() != d2.size())
		{
			cout << i - 1;
			break;
		}

	}


	return 0;
}