#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;
ll n, m, qwq;
struct Node
{
    ll c, tag; /* data */
};
ll maxd = 1, ans = 0;
vector<ll> num, s;
vector<Node> tree;
// void update(int ind)
// {
//     tree[ind].c = tree[ind * 2].c + tree[ind * 2 + 1].c;
//     return;
// }
void build_tree(int ind, int l, int r, ll deep)
{
    if (l == r)
    {
        s[l] = 2 * maxd - maxd / deep;
        ans += num[l] * s[l];
        // tree[ind].c = num[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(ind * 2, l, mid, deep * 2);
    build_tree(ind * 2 + 1, mid + 1, r, deep * 2);
    // update(ind);
    return;
}
// void down(int ind, int l, int r)
// {
//     if (tree[ind].tag == 0)
//         return;
//     int mid = (l + r) / 2;
//     tree[ind * 2].c += tree[ind].tag * (mid - l + 1);
//     tree[ind * 2 + 1].c += tree[ind].tag * (r - mid);
//     tree[ind * 2].tag += tree[ind].tag;
//     tree[ind * 2 + 1].tag += tree[ind].tag;
//     tree[ind].tag = 0;
//     return;
// }
// ll modefy(int ind, int l, int r, int x, int y, int k)
// {
//     if (x <= l && r <= y)
//     {
//         tree[ind].c += (r - l + 1) * k;
//         tree[ind].tag += k;
//         return tree[ind].c;
//     }
//     int mid = (r + l) / 2;
//     down(ind, l, r);
//     ll sum = 0;
//     if (x <= mid)
//         sum += modefy(ind * 2, l, mid, x, y, k);
//     if (mid < y)
//         sum += modefy(ind * 2 + 1, mid + 1, r, x, y, k);
//     update(ind);
//     return sum;
// }
ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> qwq;
    num.resize(n + 1), s.resize(n + 1, 0);
    // tree.resize(4 * n + 10);
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    while (maxd <= n)
        maxd *= 2;
    build_tree(1, 1, n, 1);
    for (int i = 2; i <= n; i++)
        s[i] += s[i - 1];

    ll t = gcd(maxd, qwq);
    maxd /= t, qwq /= t;
    while (m--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        ans += (s[y] - s[x - 1]) * k;
        cout << ans / maxd * qwq << '\n';
        // cout << modefy(1, 1, n, x, y, k) * qwq << '\n';
    }
    return 0;
}