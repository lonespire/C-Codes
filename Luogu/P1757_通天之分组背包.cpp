#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;
int m, n;
struct weigh_value
{
    ll w, v;
};
vector<ll> dp;
unordered_map<int, vector<weigh_value>> item;
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        item[c].push_back({a, b});
    }
    dp.resize(m + 1, 0);
    for (auto &i : item)
    {
        for (int x = m; x >= 1; x--)
        {
            for (auto &j : i.second)
            {
                int w = j.w, v = j.v;
                if (x - w >= 0)
                    dp[x] = max(dp[x], dp[x - w] + v);
            }
        }
    }
    cout << dp[m];
    return 0;
}