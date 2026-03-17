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
#define CRT_SECURE_NO_WARNINGS
#define MAX_N 1000
#define MAX_K 10 
using namespace std;
typedef long long ll;

struct Node
{
    ll c, tagx, tagy;
    Node() : tagx(1), tagy(0) {}
};
int n, m, p;
vector<int> num;
vector<Node> c;

void update(int ind)
{
    c[ind].c = (c[ind * 2].c % p + c[ind * 2 + 1].c % p) % p;
    return;
}
void build_tree(int ind, int l, int r)
{
    if (l == r)
    {
        c[ind].c = num[l] % p;
        return;
    }
    int mid = (l + r) / 2;
    build_tree(ind * 2, l, mid);
    build_tree(ind * 2 + 1, mid + 1, r);
    update(ind);
    return;
}
void down_mul(int ind, int l, int r)
{
    if (c[ind].tagx == 1) return;
    int mid = (l + r) / 2;
    c[ind * 2].tagx = (c[ind * 2].tagx * c[ind].tagx % p) % p;
    c[ind * 2 + 1].tagx = (c[ind * 2 + 1].tagx * c[ind].tagx % p) % p;
    c[ind * 2].tagy = (c[ind * 2].tagy * c[ind].tagx % p) % p;
    c[ind * 2 + 1].tagy = (c[ind * 2 + 1].tagy * c[ind].tagx % p) % p;
    c[ind * 2].c = (c[ind * 2].c * c[ind].tagx % p) % p;
    c[ind * 2 + 1].c = (c[ind * 2 + 1].c * c[ind].tagx % p) % p;

    c[ind].tagx = 1;
    return;
}
void down_add(int ind, int l, int r)
{
    if (c[ind].tagy == 0) return;
    int mid = (l + r) / 2;
    c[ind * 2].c = (c[ind * 2].c + c[ind].tagy * (mid - l + 1)) % p;
    c[ind * 2 + 1].c = (c[ind * 2 + 1].c + c[ind].tagy * (r - mid)) % p;
    c[ind * 2].tagy = (c[ind * 2].tagy + c[ind].tagy) % p;
    c[ind * 2 + 1].tagy = (c[ind * 2 + 1].tagy + c[ind].tagy) % p;
    c[ind].tagy = 0;
    return;
}
void down(int ind, int l, int r)
{
    down_mul(ind, l, r);
    down_add(ind, l, r);
}
void modefy1(int ind, int l, int r, int x, int y, int k)
{
    if (x <= l && r <= y)
    {
        c[ind].c = (c[ind].c * k % p) % p;
        c[ind].tagx = (c[ind].tagx * k % p) % p;
        c[ind].tagy = (c[ind].tagy * k % p) % p;
        return;
    }
    int mid = (r + l) / 2;
    down(ind, l, r);
    if (mid >= x) modefy1(ind * 2, l, mid, x, y, k);
    if (mid < y) modefy1(ind * 2 + 1, mid + 1, r, x, y, k);
    update(ind);
    return;
}

void modefy2(int ind, int l, int r, int x, int y, ll k)
{
    if (x <= l && r <= y)
    {
        c[ind].c = (c[ind].c + (r - l + 1) * k) % p;
        c[ind].tagy = (c[ind].tagy + k) % p;
        return;
    }
    int mid = (r + l) / 2;
    down(ind, l, r);
    if (mid >= x) modefy2(ind * 2, l, mid, x, y, k);
    if (mid < y) modefy2(ind * 2 + 1, mid + 1, r, x, y, k);
    update(ind);
    return;
}
ll query(int ind, int l, int r, int x, int y)
{
    if (x <= l && r <= y) return c[ind].c % p;
    int mid = (l + r) / 2;
    ll sum = 0;
    down(ind, l, r);
    if (x <= mid) sum = (sum + query(ind * 2, l, mid, x, y) % p) % p;
    if (mid < y) sum = (sum + query(ind * 2 + 1, mid + 1, r, x, y) % p) % p;
    return sum % p;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> p;
    num.resize(n + 1);
    c.resize(4 * n + 5);
    for (int i = 1; i <= n; i++) cin >> num[i];
    build_tree(1, 1, n);
    while (m--)
    {
        int operate;
        cin >> operate;
        if (operate == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            modefy1(1, 1, n, x, y, k);
        }
        else if (operate == 2)
        {
            int x, y, k;
            cin >> x >> y >> k;
            modefy2(1, 1, n, x, y, k);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) % p << '\n';
        }
    }

    return 0;
}