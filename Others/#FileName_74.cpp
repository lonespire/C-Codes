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



deque<string> Number;
bool cmp(string a, string b)
{
	return a + b > b + a;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;
		Number.push_back(temp);
	}
	sort(Number.begin(), Number.end(), cmp);
	for (int i = 0; i < n; i++)cout << Number[i];
	
	return 0;
}