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
int f[MAX_N] = { 0 };
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	f[1] = k;
	f[2] = k * (k - 1);
	f[3] = k * (k - 1) * (k - 2);
	for (int ws = 4; ws <= n; ws++)
	{
		f[ws] = (k - 2) * f[ws - 1] + (k - 1) * f[ws - 2];
	}
	
	cout << f[n	];
	
	return 0;
}