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
#define CRT_SECURE_NO_WARNINGS
#define MAX_N 1000
#define MAX_K 10
using namespace std;



int num[8];
unordered_map<int, int> cnt;
vector<int> n;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	for (int i = 1; i <= 7; i++)
	{
		cin >> num[i];
		cnt[num[i]]++;
	}
	bool flag1=0, flag2=0;
	for (auto& temp : cnt)
	{
		n.push_back(temp.second);
	}
	sort(n.begin(), n.end(),cmp);
	if (n[0] >= 3 && n[1] >= 2)
	{
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}
