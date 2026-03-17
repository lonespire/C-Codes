#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;
struct Node
{
    ll sum, suml, sumr;
};

vector<ll> num;
vector<Node> a;
int n, m;
ll ans = INT_MIN;
void update(int ind)
{
    a[ind].suml = max(a[ind * 2].sum + a[ind * 2 + 1].suml, a[ind * 2].suml);
    a[ind].sumr = max(a[ind * 2 + 1].sumr, a[ind * 2 + 1].sum + a[ind * 2].sumr);
    a[ind].sum = max(a[ind * 2].sum, a[ind * 2 + 1].sum);
    a[ind].sum = max(a[ind].sum, a[ind * 2].sumr + a[ind * 2 + 1].suml);
    return;
}
void build(int ind, int l, int r)
{
    if (l == r)
    {
        a[ind].sum = a[ind].suml = a[ind].sumr = num[l];
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l, mid);
    build(ind * 2 + 1, mid + 1, r);
    update(ind);
    return;
}
void modefy(int ind, int l, int r, int x, ll y)
{
    if (l == r & l == x)
    {
        a[ind].sum = a[ind].suml = a[ind].sumr = y;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        modefy(ind * 2, l, mid, x, y);
    else
        modefy(ind * 2 + 1, mid + 1, r, x, y);
    update(ind);
    return;
}
// ll query(int ind, int l, int r, int x, int y)
// {
//     if (x <= l && r <= r)
//     {
//         return a[ind];
//     }
//     int mid = (l + r) / 2;
//     int sum = 0;
//     if (mid >= x)
//         sum += query(ind * 2, l, mid, x, y);
//     else
//         sum += query()
// }
void swap(int &a, int &b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    return;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    num.resize(n + 1);
    a.resize(4 * n + 5);

    for (int i = 1; i <= n; i++)
        cin >> num[i];
    while (m--)
    {
        int k, x, y;
        cin >> k >> x >> y;
        swap(x, y);
        if (k == 1)
        {
            // cout << query(1, 1, n, x, y);
        }
        else
        {
        }
    }

    return 0;
}