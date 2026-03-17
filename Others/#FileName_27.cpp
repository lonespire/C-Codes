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
#define MAX_N 1000
#define MAX_K 10
using namespace std;

deque<int> num,d;




int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0, temp; i < n && (cin >> temp); i++) num.push_back(temp);
	for (int i = 0; i < n; i++)
	{
		while (!d.empty()&&num[i] < num[d.back()]) d.pop_back();
		if (!d.empty() && i - d.front() == k) d.pop_front();
		d.push_back(i);
		if (i >= k - 1&&!d.empty())
		{
			if (i != k - 1)cout << " ";
			cout << num[d.front()];
		}
	}
	cout << endl;
	d.clear();
	for (int i = 0; i < n; i++)
	{
		while (!d.empty()&&num[i] > num[d.back()]) d.pop_back();
		if (!d.empty() && i - d.front() == k) d.pop_front();
		d.push_back(i);
		if (i >= k - 1&&!d.empty())
		{
			if (i != k - 1)cout << " ";
			cout << num[d.front()];
		}
	}
	return 0;
}