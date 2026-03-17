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
#define MAX_N 200
#define MAX_K 10
using namespace std;


int f[MAX_N] = {0};



int main()
{
	int n;
	cin >> n;
	f[1] = 2;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] * 2 + 2;
	}

	cout << f[n];
	return 0;
}