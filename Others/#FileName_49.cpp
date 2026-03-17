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
#define CRT_SECURE_NO_WARNINGS
using namespace std;

struct Node
{
	int c, l, r;
};
int num[10000005];
vector<int> root;
	Node tree[40000005];
	int cnt = 0;
	int clone(int ind)
	{
		cnt++;
		tree[cnt] = tree[ind];
		return cnt;
	}
	int build_tree(int l, int r)
	{
		int ind = ++cnt;
		if (l == r)
		{
			tree[ind].c = num[l];
			return ind;
		}
		int mid = (l + r) / 2;
		tree[ind].l = build_tree(l, mid);
		tree[ind].r = build_tree(mid + 1, r);
		return ind;
	}
	int modify(int ind, int l, int r, int b, int c)
	{
		ind = clone(ind);
		if (l == r)
		{
			tree[ind].c = c; 
			return ind;
		}
		int mid = (l + r) / 2;
		if (b <= mid)tree[ind].l = modify(tree[ind].l, l, mid, b, c);
		else tree[ind].r = modify(tree[ind].r, mid + 1, r, b, c);
		return ind;
	}
	int query(int ind, int l, int r, int b)
	{
		if (l == r) return tree[ind].c;
		int mid=(l + r) / 2;
		if (b <= mid)return query(tree[ind].l, l, mid, b);
		else return query(tree[ind].r, mid + 1, r, b);
	}



int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
	root.push_back(build_tree(1,n));
	for (int i = 0; i < m; i++)
	{
		int v, a, b, c;
		scanf("%d%d%d", &v, &a, &b);
		if (a == 1)
		{
			scanf("%d", &c);
			root.push_back(modify(root[v], 1, n, b, c));
		}
		else
		{
			printf("%d\n", query(root[v], 1, n, b));
			root.push_back(root[v]);
		}
	}
	return 0;
}