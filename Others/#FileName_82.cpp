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
#define MAX_N 2005
#define MAX_K 10
using namespace std;
typedef long long ll;

struct Cow
{
	ll begin, end;
}cow[MAX_N];
struct Sun_cream
{
	ll strenth,number;
}cream[MAX_N];
bool cmp1(Cow a, Cow b)
{
	if(a.end!=b.end)return a.end < b.end;
	return a.begin < b.begin;
}
bool cmp2(Sun_cream a,Sun_cream b)
{
	return a.strenth < b.strenth;
}

int main()
{
	int C, L,ans=0;
	cin >> C >> L;
	for (int i = 1; i <= C; i++)cin >> cow[i].begin >> cow[i].end;
	for (int i = 1; i <= L; i++)cin >> cream[i].strenth >> cream[i].number;
	sort(cow+1, cow + C+1, cmp1);
	sort(cream+1, cream + L+1, cmp2);
	for (int i = 1; i <= C;i++)
	{
		for (int j = 1; j <= L; j++)
		{
			if (cream[j].strenth <= cow[i].end && cream[j].strenth >= cow[i].begin && cream[j].number > 0)
			{
				ans++;
				cream[j].number--;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}