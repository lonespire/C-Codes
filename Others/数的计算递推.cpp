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
#define MAX_N 1000
#define MAX_K 10
using namespace std;
int f[MAX_N + 5] = { 0 };
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for (int j = 1; j <= i / 2; j++)
		{
			f[i] += f[j];
		}
	}
	cout << f[n];
	return 0;
}