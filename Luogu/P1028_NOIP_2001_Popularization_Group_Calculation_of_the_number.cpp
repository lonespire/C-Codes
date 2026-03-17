#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i / 2; j++)
        {
            dp[i] += dp[j];
        }
    }
    cout << dp[n];
    return 0;
}