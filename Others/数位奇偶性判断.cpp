#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = (a[0] == 1 || a[0] == -1);
        dp[0][0] = 0;
        // cout << dp[0][1] << " " << dp[0][0] << " ||" << 0 << endl;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == 1)
            {
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + 1) % 998244353;
                dp[i][0] = 0;
            }
            else if (a[i] == 0)
            {
                dp[i][1] = 0;
                dp[i][0] = (dp[i - 1][1]) % 998244353;
            }
            else if (a[i] == -1)
            {
                dp[i][1] = (dp[i - 1][0] + 1) % 998244353;
                dp[i][0] = (dp[i - 1][1]) % 998244353;
            }
            // cout << dp[i][1] << " " << dp[i][0] << " ||" << i << endl;
        }
        if (a[n - 1] == 1)
            cout << (dp[n - 1][1]) % 998244353 << endl;
        else if (a[n - 1] == 0)
            cout << (dp[n - 1][0]) % 998244353 << endl;
        else if (a[n - 1] == -1)
            cout << (dp[n - 1][1] + dp[n - 1][0]) % 998244353 << endl;
        // break;
    }
    return 0;
}
/*
3
3
1 0 1
3
0 0 0
3
1 -1 1
*/