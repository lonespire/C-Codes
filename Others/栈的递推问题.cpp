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
#define MAX_N 18
#define MAX_K 10
using namespace std;

int f[MAX_N+5] = { 0 };




int main()
{
	int n;
	cin >> n;
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			f[i] +=  f[j - 1] * f[i - j];
		}

	}
	cout << f[n];

	return 0;
}