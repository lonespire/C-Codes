#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct mole
{
    int t, i, j;
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<mole> fight(m);
    for (auto &i : fight)
        cin >> i.t >> i.i >> i.j;
    vector<int> dp(m, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(fight[i].i - fight[j].i) + abs(fight[i].j - fight[j].j) <= fight[i].t - fight[j].t)
                dp[i] = max(dp[j], dp[i]);
        }
        dp[i]++;
    }
    int ans = 0;
    for (auto &i : dp)
        ans = max(ans, i);
    cout << ans;
    return 0;
}