#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// inline int read()
// {
//     int x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//     {
//         x = x * 10 + ch - 48;
//         ch = getchar();
//     }
//     return x * f;
// }
int n, m;
vector<int> a, lg;
vector<vector<int>> st;
void init_st()
{
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    for (int k = 1; k <= lg[n]; k++)
    {
        for (int i = 1; i <= n - (1 << k) + 1; i++)
        {
            st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
}
int query1(int l, int r)
{
    int ans = -1, i = 0, len = r - l + 1;
    while (len)
    {
        if (len & 1)
            ans = max(ans, st[l][i]), l += (1 << i);
        len >>= 1;
        i++;
    }
    return ans;
}
int query2(int l, int r)
{
    int ans = 0, k = lg[r - l + 1];
    ans = max(st[l][k], st[r - (1 << k) + 1][k]);
    return ans;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    a.reserve(n + 1), st.resize(n + 1, vector<int>((int)(log2(n + 1)) + 1)), lg.reserve(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init_st();
    int l, r;
    while (m--)
    {
        cin >> l >> r;
        cout << query2(l, r) << '\n';
    }
    return 0;
    // system("pause");
}