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


vector<int> num;
class Tree
{
public:
	vector<int> tree;
	Tree(int n): tree(4*n+1){}
	void update(int index)
	{
		tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
		return;
	}
	void build_tree(int index, int l, int r)
	{
		if (l == r)
		{
			tree[index] = num[l];
			return;
		}
		int mid = (l + r) / 2;
		build_tree(index * 2, l, mid);
		build_tree(index * 2 + 1, mid + 1, r); 
		update(index);
		return;
	}
	void modify(int index, int l, int r, int b, int c)
	{
		if (l == r)
		{
			if(l == b)tree[index] = c;
			return;
		}
		int mid = (l + r) / 2;
		if (b <= mid) modify(index * 2, l, mid, b, c);
		else modify(index * 2 + 1, mid + 1, r, b, c);
		update(index);
		return;
	}
	int query(int index, int l, int r, int b, int c)
	{
		if (b <= l && r <= c) return tree[index];
		int mid = (l + r) / 2;
		int ans = INT_MIN;
		if (b <= mid)ans=max(ans, query(index * 2, l, mid, b, c));
		if (mid + 1 <= c)ans = max(ans, query(index * 2 + 1, mid + 1, r, b, c));
		return ans;
	}
};



int main()
{
	int n, m;
	cin >> n >> m;
	num.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	Tree tree(n + 1);
	tree.build_tree(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			if (b > c)continue;
			else tree.modify(1, 1, n, b, c);
		}
		else
		{
			if (b > c) cout << -2147483648 << endl;
			else cout << tree.query(1, 1, n, b, c)<<endl;
		}
	}
	return 0;
}