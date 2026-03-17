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


void add(string x, string y)
{
	if (x.size() < y.size())
	{
		string temp;
		temp = x;
		x = y;
		y = temp;
	}
	vector<int> a, b;
	a.resize(x.size()+5,0);
	b.resize(y.size()+5,0);
	int a_num = x.size();
	for (int i = x.size() - 1; i >= 0; i--)
	{
		a[x.size() - i] = x[i] - '0';//第一位开始/////////
	}
	for (int i = y.size() - 1; i >= 0; i--)
	{
		b[y.size() - i] = y[i] - '0';
	}
	for (int i = 1; i <= y.size(); i++)
	{
		a[i] += b[i];
		
	}
	for (int i = 1; i <= x.size(); i++)
	{
		if (a[i] >= 10)
		{
			if (i == a_num)a_num++;
			a[i + 1]++;
			a[i] %= 10;
		}
	}
	for (int i = a_num; i >=1; i--)
	{
		cout << a[i];
	}
	cout << endl;
}



int main()
{
	::ios::sync_with_stdio;
	cin.tie(nullptr);
	int m;
	cin >> m;

	while (m--)
	{
		string a, b;
		cin >> a >> b;
		add(a, b);
	}

	return 0;
}
