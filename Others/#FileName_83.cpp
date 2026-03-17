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
#define MAX_N 50005
#define MAX_K 10
using namespace std;

struct Cattle
{
	long long begin, end, machineID;
};

Cattle cattle[MAX_N];
int machine[MAX_N], index[MAX_N];
bool cmp(int a, int b)
{
	if (cattle[a].begin != cattle[b].begin)return cattle[a].begin < cattle[b].begin;
	else return a < b;
}
int main()
{
	fill(machine, machine + MAX_N, -1);
	int n, MAX = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> cattle[i].begin >> cattle[i].end;
		index[i] = i;
	}
	sort(index + 1, index + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		int id = index[i];
		for (int j = 1; j <= MAX + 1; j++)
		{
			if (machine[j] < cattle[id].begin)
			{
				cattle[id].machineID = j;
				machine[j] = cattle[id].end;
				MAX = max(MAX, j);
				break;
			}
		}
	}
	cout << MAX << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << cattle[i].machineID << endl ;
	}
	return 0;
}