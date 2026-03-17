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
typedef long long ll;
vector<ll> num;
class Tree
{
public:
	struct Node {
		ll sum, tag, l, r;
		Node() :sum(0), tag(0) {}
	};
	vector<Node> tree;
	Tree(ll n) : tree(4 * n + 5) {}
	void update(ll index)
	{
		tree[index].sum = tree[index * 2].sum + tree[index * 2 + 1].sum;
		return;
	}
	void build_tree(ll index, ll l, ll r)
	{
		tree[index].l = l;
		tree[index].r = r;
		if (l == r)
		{
			tree[index].sum = num[l];
			return;
		}
		ll mid = (l + r) / 2;
		build_tree(index * 2, l, mid);
		build_tree(index * 2 + 1, mid + 1, r);
		update(index);
	}
	void down(ll index)
	{
		if (tree[index].tag == 0) return;
		tree[index * 2].tag += tree[index].tag;
		tree[index * 2].sum += tree[index].tag * (tree[index * 2].r - tree[index * 2].l + 1);
		tree[index * 2 + 1].tag += tree[index].tag;
		tree[index * 2 + 1].sum += tree[index].tag * (tree[index * 2 + 1].r - tree[index * 2 + 1].l + 1);
		tree[index].tag = 0;
	}
	void modify(int index, int l, int r, int b, int c, ll d)
	{
		if (l >= b && c >= r)
		{
			tree[index].tag += d;
			tree[index].sum += d * (r - l + 1);
			return;
		}
		int mid = (l + r) / 2;
		down(index);
		if (b <= mid) modify(index * 2, l, mid, b, c, d);
		if (c > mid)modify(index * 2 + 1, mid + 1, r, b, c, d);
		update(index);
		return;
	}
	ll query(int index, int l, int r, int b, int c)
	{
		if (l >= b && c >= r)
		{
			return tree[index].sum;
		}
		int mid = (l + r) / 2;
		down(index);
		ll sum = 0;
		if (b <= mid) sum += query(index * 2, l, mid, b, c);
		if (c > mid)sum += query(index * 2 + 1, mid + 1, r, b, c);
		return sum;
	}
private:

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
	Tree tree(n);
	tree.build_tree(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b, c, d;
			cin >> b >> c >> d;
			if (b > c)continue;
			tree.modify(1, 1, n, b, c, d);
		}
		else
		{
			int b, c;
			cin >> b >> c;
			if (b > c)cout << 0 << endl;
			else cout << tree.query(1, 1, n, b, c) << endl;
		}
	}
	return 0;
}