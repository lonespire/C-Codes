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
#define MAX_N 100005
#define MAX_K 10
using namespace std;


struct Machine
{
	int max_time, max_difficulty, used;
}machine[MAX_N];
struct Mask
{
	int time_need, difficulty;
}mask[MAX_N];
bool cmp1(Machine a, Machine b)
{
	if (a.max_time != b.max_time)return a.max_time < b.max_time;

	return a.max_difficulty < b.max_difficulty;
}
bool cmp2(Mask a, Mask b)
{
	if (a.time_need != b.time_need)return a.time_need > b.time_need;
	return a.difficulty > b.difficulty;
}
int main()
{
	int n, m;
	long long ans1 = 0, ans2 = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> machine[i].max_time >> machine[i].max_difficulty;
		machine[i].used = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> mask[i].time_need >> mask[i].difficulty;
	}
	sort(machine + 1, machine + n + 1, cmp1);
	sort(mask + 1, mask + m + 1, cmp2);
	int cur = n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			/*if (machine[j].max_time > mask[i].time_need)cur = j;*/
			if (machine[j].max_difficulty >= mask[i].difficulty && machine[j].max_time >= mask[i].time_need && machine[j].used)
			{
				ans1++;
				ans2 += 500 * mask[i].time_need + 2 * mask[i].difficulty;
				machine[j].used = 0;
				break;
			}

		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}