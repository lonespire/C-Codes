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

int n,ans=INT_MAX;
string a, b;
vector< pair<string, string>> f_t;
unordered_map<string, int> dp;
void dfs(string cur, int cnt,int MAX_cnt)
{
	if (cnt > MAX_cnt) return;
	if (cnt > 10) return;
	dp[cur] = cnt;
	if (cnt >= ans) return;
	if (cur == b)
	{
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		string f, t;
		f = f_t[i].first;
		t = f_t[i].second;
		int pos = -1;
		pos = cur.find(f);
		while (pos != -1)
		{
			string temp = cur;
			temp.replace(pos, f.size(), t);
			if(!dp.count(temp) || dp[temp]>cnt + 1)dfs(temp, cnt + 1,MAX_cnt);
			pos = cur.find(f, pos + 1);
		}
	}
}


int main()
{
	cin >> a >> b; 
	string temp1, temp2;
	while(cin >> temp1 >> temp2)
	{
		f_t.push_back(make_pair(temp1, temp2));
	}
	for (int i = 0; i < n; i++)
	{
		cout << f_t[i].first << " " << f_t[i].second << endl;
	}
	n = f_t.size();
	for (int i = 1; i <= 10; i++)
	{
		dp.clear();
		dfs(a, 0,i);
		if (ans != INT_MAX)
		{
			cout << ans;
			return 0;
		}
	}
	cout << "NO ANSWER!";
	return 0;
}