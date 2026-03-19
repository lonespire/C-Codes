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

int ans = 0;
int n,vis[21];
string word[21];
int overlap(string a, string b)
{
	int num_lap = 0;
	for (int i = 1; i < a.size(); i++)
	{
		int cnt = 0;
		if (a[i] != b[0])continue;
		for (int j = 0; j < b.size()-1 && j + i < a.size();j++)
		{
			if (a[j + i] != b[j]) break;
			cnt++;
			if (j + i == a.size() - 1 && j != b.size() - 1) num_lap = max(num_lap, cnt);
		}
	}
	return num_lap;
}
//int overlap(string& s1, string& s2) {
//	for (int i = s1.size() - 1; i >= 1; i--) {
//		int flag = 1;
//		for (int j = 0; j < s1.size() - i; j++) {
//			if (s1[i + j] == s2[j]) continue;
//			flag = 0;
//			break;
//		}
//		if (flag == 1) return s1.size() - i;
//	}
//	return 0;
//}
string merge(string a, string b,int num_lap)
{
	return a + b.substr(num_lap);
}
void dfs(string cur, int l)
{
	ans = max(ans, l);
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 2) continue;
		int num_lap = overlap(cur, word[i]);
		if (!num_lap) continue;
		vis[i]++;
		dfs(merge(cur, word[i], num_lap), l + word[i].size() - num_lap);
		vis[i]--;
	}
	return;
}

int main()
{
	char head;
	fill(vis, vis + 21, 0);
	cin >> n ;
	for (int i = 1; i <= n; i++) cin >> word[i];
	cin >> head;

	for (int i = 1; i <= n; i++)
	{
		if (word[i][0] != head) continue;
		vis[i]++;
		dfs(word[i], word[i].size());
		vis[i]--;
	}
	cout << ans;
	//cout << overlap("111111111111", "111111");
	return 0;
}