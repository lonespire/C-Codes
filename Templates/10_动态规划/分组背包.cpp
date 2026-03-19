#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, v;
    cin >> n >> v;
    vector<vector<pair<int, int>>> item(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        item[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> item[i][j].first >> item[i][j].second;
        }
    }
    vector<int> dp(v + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int k = v; k >= 1; k--)
        {
            for (auto j : item[i])
            {
                if (j.first > k)
                    continue;
                dp[k] = max(dp[k], dp[k - j.first] + j.second);
            }
        }
    }
    cout << dp[v];
    return 0;
}