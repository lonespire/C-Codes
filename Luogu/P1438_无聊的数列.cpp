#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;

int n, m;
struct Node
{
    ll c, tag; /* data */
    Node() : tag(0) {}
};
vector<int> num;
vector<Node> tree;
void update(int ind)
{
    tree[ind].c = tree[ind * 2].c + tree[ind * 2 + 1].c;
    return;
}
void build_tree(int ind, int l, int r)
{
    if (l == r)
    {
        tree[ind].c = num[l] - num[l - 1];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(ind * 2, l, mid);
    build_tree(ind * 2 + 1, mid + 1, r);
    update(ind);
    return;
}
void down(int ind, int l, int r)
{
    if (tree[ind].tag == 0)
        return;
    int mid = (r + l) / 2;
    tree[ind * 2].c += tree[ind].tag * (mid - l + 1);
    tree[ind * 2].tag += tree[ind].tag;
    tree[ind * 2 + 1].c += tree[ind].tag * (r - mid);
    tree[ind * 2 + 1].tag += tree[ind].tag;
    tree[ind].tag = 0;
    return;
}
void modefy(int ind, int l, int r, int x, int y, ll k)
{
    if (x > y)
        return;
    if (x <= l && r <= y)
    {
        tree[ind].tag += k;
        tree[ind].c += k * (r - l + 1);
        return;
    }
    int mid = (l + r) / 2;
    down(ind, l, r);
    if (x <= mid)
        modefy(ind * 2, l, mid, x, y, k);
    if (mid < y)
        modefy(ind * 2 + 1, mid + 1, r, x, y, k);
    update(ind);
    return;
}
ll query(int ind, int l, int r, int x, int y)
{
    if (x > y)
        return 0;
    if (x <= l && r <= y)
    {
        return tree[ind].c;
    }
    int mid = (r + l) / 2;
    ll sum = 0;
    down(ind, l, r);
    if (x <= mid)
        sum += query(ind * 2, l, mid, x, y);
    if (mid < y)
        sum += query(ind * 2 + 1, mid + 1, r, x, y);
    return sum;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    tree.resize(4 * n + 5);
    num.resize(n + 1), num[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    build_tree(1, 1, n);
    while (m--)
    {
        int o;
        cin >> o;
        if (o == 1)
        {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            modefy(1, 1, n, l, l, k);
            if (l + 1 <= r)
                modefy(1, 1, n, l + 1, r, d);
            if (r + 1 <= n)
                modefy(1, 1, n, r + 1, r + 1, -(k + (r - l) * d));
        }
        else
        {
            int p;
            cin >> p;
            cout << query(1, 1, n, 1, p) << '\n';
        }
    }

    return 0;
}