#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, v;
    cin >> n >> v;
    vector<pair<int, int>> item(n);
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].first >> item[i].second;
    }
    vector<int> dp(v + 1, 0);
    for (auto i : item)
    {
        for (int j = i.first; j <= v; j++)
        {
            dp[j] = max(dp[j], dp[j - i.first] + i.second);
        }
    }
    cout << dp[v];
    return 0;
}