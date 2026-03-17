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

class Tree
{
public:
	vector<int> c;
	Tree(int n) : c(n + 1, 0) {}
	int lowbit(int x) {
		return (x & -x);
	}
	void add(int i, int x)
	{
		while (i < c.size())
		{
			c[i] += x;
			i += lowbit(i);
		}
		return;
	}
	int query(int i)
	{
		int sum = 0;
		while (i)
		{
			sum += c[i];
			i -= lowbit(i);
		}
		return sum;
	}
private:

};




int main()
{
	vector<int> num;
	int n, m;
	cin >> n >> m;
	num.resize(n);
	Tree tree(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		if (i == 0)
			tree.add(1, num[i]);
		else tree.add(i + 1, num[i]-num[i-1]);
	}
	for (int i = 0; i < m; i++)
	{
		int temp; 
		cin >> temp;
		if (temp == 1)
		{
			int x, y, k;
			cin >> x >> y >> k;
			tree.add(x, k);
			tree.add(y+1, -k);
		}
		else
		{
			int x;
			cin >> x;
			cout << tree.query(x)<<endl;
		}
	}
	return 0;
}