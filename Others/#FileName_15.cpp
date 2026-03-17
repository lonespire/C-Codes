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
#define MASK(n) ((1 << (n + 1)) - 2)



unordered_map<int, int> bitmask;
int cnt = 3;
int arr[20];
void print_result(int n)
{
	cnt--;
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)cout << " ";
		cout << arr[i];
	}
	cout << endl;
	return;
}
int dfs(int i, int t1, int t2, int t3, int n)
{
	if (i > n)
	{
		if(cnt>0) print_result(n);
		return 1;
	}
	int ans = 0;
	for (int t = t1; t; t -= (-t & t))
	{
		int j = bitmask[-t & t];
		if ((t2 & (1 << (i + j - 1))) && (t3 & (1 << (i - j + n))))
		{
			arr[i] = j;
			ans+=dfs(i + 1, t1 ^ (1 << j), t2 ^ (1<< (i + j - 1)), t3 ^ (1<< (i - j + n)), n);
		}
	}
	return ans;
}



int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= 2 * n; i++) bitmask[1 << i] = i;
	int ans=dfs(1, MASK(n), MASK(2 * n - 1), MASK(2 * n - 1),n);
	cout << ans << endl;

	return 0;
}