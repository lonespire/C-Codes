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
//#define CRT_SECURE_NO_WARNINGS
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;

vector<ll> num;
int cnt = 0;
struct Node
{
	int ind,  l, r;
	ll c, tag;
	Node() : ind(0), c(0), l(0), r(0), tag(0) {}
};
vector<Node> tree;
int root;
void update(int ind,int l,int r)
{
	tree[ind].c = tree[l].c + tree[r].c;
	return;
}
int build_tree(int l, int r)
{
	int ind = tree.size();
	tree.emplace_back();//////////////////////////////
	tree[ind].ind = ind;
	if (l == r)
	{
		tree[ind].c = num[l];
		return ind;
	}
	int mid = (l + r) / 2;
	tree[ind].l = build_tree(l, mid);
	tree[ind].r = build_tree(mid + 1, r);
	update(ind, tree[ind].l, tree[ind].r);
	return ind;
}
void down(int ind,int l,int r,int num1,int num2	)
{
	if (!tree[ind].tag)return;
	tree[l].tag += tree[ind].tag;
	tree[r].tag += tree[ind].tag;
	tree[l].c += tree[ind].tag * num1;
	tree[r].c += tree[ind].tag * num2;
	tree[ind].tag = 0;
	return;
}
void add(int ind, int l, int r, int a, int b, ll c)
{
	if (a <= l && r <= b)
	{
		tree[ind].tag +=  c;
		tree[ind].c += (r - l + 1) * c;
		return;
	}
	int mid = (l + r) / 2;
	down(ind, tree[ind].l, tree[ind].r, (mid - l + 1), (r - mid));
	if (a <= mid) add(tree[ind].l, l, mid, a, b, c);
	if (mid + 1 <= b) add(tree[ind].r, mid + 1, r, a, b, c);
	update(ind, tree[ind].l, tree[ind].r);
	return;
}
ll query(int ind, int l, int r,int a,int b)
{

	if (a <= l && r <= b)
	{
		return tree[ind].c;
	}
	int mid = (l + r) / 2;
	ll sum = 0;
	down(ind, tree[ind].l, tree[ind].r, (mid - l + 1), (r - mid));
	if(a<=mid) sum += query(tree[ind].l, l, mid, a, b);
	if(mid+1<=b) sum += query(tree[ind].r, mid + 1, r, a, b);
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	//scanf("%d %d", &n,&m);
	cin >> n >> m;
	num.resize(n + 1);
	for (int i = 1; i <= n; i++)cin >> num[i];
		//scanf(" %lld",&num[i]) ;
	tree.reserve(4 * n);
	root = build_tree(1, n);
	while (m--)
	{
		char operate;
		ll a, b;
		cin >> operate >> a >> b;
		//scanf(" %c%lld%lld", &operate, &a, &b);
		if (operate == 'C')
		{
			ll c;
			cin >> c;
			//scanf("%lld", &c);
			add(root, 1, n, a, b, c);
		}
		else cout << query(root, 1, n, a, b) <<'\n';
			//printf("%lld\n", query(root, 1, n, a, b));
	}
	return 0;
}
