#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= min(k, i); j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
        }
    }
    cout << dp[n][k];
    return 0;
}