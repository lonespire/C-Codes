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
#include <unordered_map>
#define MAX_N 1000
#define MAX_K 10
using namespace std;

unordered_map<int, int> bitmask;
int n[5],ans=0,sum=INT_MAX;
vector<int> s[5];
void dfs(int cnt, int time1, int time2,int subject)
{
	if (cnt==n[subject])
	{
		sum = min(sum, max(time1, time2));
		//cout << time1<<" "<<time2 << endl;
		return;
	}
	dfs(cnt+1, time1 + s[subject][cnt], time2, subject);
	dfs(cnt+1, time1 , time2 + s[subject][cnt], subject);
	return;
}

int main()
{
	for (int i = 0; i <= 21; i++) bitmask[1 << i] = i;
	for (int i = 1; i <= 4; i++)cin >> n[i];
	for (int i = 1; i <= 4; i++)
		for (int j = 1, temp; j <= n[i] && (cin >> temp); j++) s[i].push_back(temp);
	for (int i = 1; i <= 4; i++)
	{
		sum = INT_MAX;
		dfs(0, 0, 0, i);
		ans += sum;
		//cout << endl << sum;
		//cout << endl << endl;
	}
	cout << ans;
	return 0;
}